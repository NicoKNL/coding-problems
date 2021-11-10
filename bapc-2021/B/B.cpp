#include <bits/stdc++.h>

typedef long long T;
using namespace std;

struct Event
{
    string name;
    T strength;
    T count;
    T threshold;
    bool is_picked;
    T guaranteed_count;

    void addOccurrence(T t, T &k)
    {
        ++count;
        threshold = max(threshold, t);
        T diff = threshold - strength;
        if (strength < threshold)
        {
            k -= diff;
            strength = threshold;
        }
    }

    T sortScore() const
    {
        if (is_picked)
        {
            return count;
        }
        else
        {
            return (strength + 1) * (count - guaranteed_count);
        }
    }

    bool operator<(const Event &other) const
    {
        return sortScore() < other.sortScore();
    }
};

ostream &operator<<(ostream &os, const Event &e)
{
    cout << "name: " << e.name << endl
         << "strength: " << e.strength << endl
         << "count: " << e.count << endl
         << "threshold: " << e.threshold << endl;

    return os;
}

unordered_map<string, Event>
parseAttrs(T n)
{
    unordered_map<string, Event> attrs;

    while (n > 0)
    {
        string name;
        T strength;
        cin >> name >> strength;
        attrs[name] = Event{name, strength, 0, 0, false, 0};
        --n;
    }

    return attrs;
}

vector<Event> parseEvents(unordered_map<string, Event> &attrs, T &k)
{
    T l;
    cin >> l;
    vector<Event> events;
    while (l > 0)
    {
        string name;
        T threshold;
        cin >> name >> threshold;

        // Mark event
        events.push_back(Event{name, 0, 0, threshold, false, 0});

        // Update attribute
        attrs[name]
            .addOccurrence(threshold, k);

        // Early out if we need to overspend k
        if (k < 0)
        {
            cout << 0 << endl;
            exit(0);
        }
        --l;
    }

    return events;
}

priority_queue<Event> buildOptionList(unordered_map<string, Event> &attrs)
{
    priority_queue<Event> options;
    for (auto &a : attrs)
    {
        // cout << a.second;
        options.push(a.second);
    }

    return options;
}

T calculatePoints(unordered_map<string, Event> &attrs, vector<Event> &events, T &k)
{
    priority_queue<Event> options = buildOptionList(attrs);

    T score = 0;
    // cout << "init k: " << k << endl;
    while (k > 0)
    {
        Event option = options.top();
        // cout << option;
        options.pop();
        // cout << "k: " << k << endl;

        if (option.is_picked)
        {
            score += option.count * k;
            // cout << "picked already, adding: " << option.count * k << endl;
            k = 0;
        }
        else // not yet picked
        {
            option.is_picked = true;
            score += (option.strength + 1) * option.count;
            // cout << "not picked yet, adding: " << (option.strength + 1) * option.count << endl;
            k -= 1;
        }

        options.push(option);
    }

    while (!options.empty())
    {
        Event option = options.top();
        options.pop();

        if (option.is_picked)
        {
            attrs[option.name].is_picked = true;
        }
    }

    return score;
}

void setGuaranteedPoints(unordered_map<string, Event> &attrs, vector<Event> &events)
{
    for (auto &e : events)
    {
        if (attrs[e.name].strength > e.threshold)
        {
            ++attrs[e.name].guaranteed_count;
        }
    }
}

T calculateGuaranteedPoints(unordered_map<string, Event> &attrs, vector<Event> &events)
{
    T score = 0;
    for (auto &e : events)
    {
        // cout << attrs[e.name].name << " " << attrs[e.name].is_picked << endl;
        if (!attrs[e.name].is_picked && e.threshold < attrs[e.name].strength)
        {
            score += attrs[e.name].strength;
        }
    }

    return score;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.precision(20);

    // PARSE INPUTS
    T n, k;
    cin >> n >> k;

    unordered_map<string, Event> attrs = parseAttrs(n);

    vector<Event> events = parseEvents(attrs, k);

    setGuaranteedPoints(attrs, events);
    T score = calculatePoints(attrs, events, k);
    score += calculateGuaranteedPoints(attrs, events);

    cout << score << endl;

    return 0;
}
