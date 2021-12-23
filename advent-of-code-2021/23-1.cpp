#include <bits/stdc++.h>
#include <sys/resource.h>

using namespace std;

struct GameState;
unordered_map<string, int> MEMO;
unordered_map<char, int> COST = {
    {'A', 1},
    {'B', 10},
    {'C', 100},
    {'D', 1000},
};
vector<string> MOVES = {
    "HALLWAY",
    "ROOM_A",
    "ROOM_B",
    "ROOM_C",
    "ROOM_D",
};

enum Location
{
    HALLWAY,
    ROOM_A,
    ROOM_B,
    ROOM_C,
    ROOM_D
};

struct Move
{
    Location from;
    Location to;

    int from_loc;
    int to_loc;
};

ostream &operator<<(ostream &os, const Move &m)
{
    os << "from: " << MOVES[m.from] << " " << m.from_loc << endl;
    os << "to: " << MOVES[m.to] << " " << m.to_loc << endl;
    return os;
}

struct GameState
{
    string hallway;
    string room_a;
    string room_b;
    string room_c;
    string room_d;

    int cost;

    GameState(string top, string bottom)
    {
        hallway = "...........";

        room_a = top[0];
        room_b = top[1];
        room_c = top[2];
        room_d = top[3];

        room_a += bottom[0];
        room_b += bottom[1];
        room_c += bottom[2];
        room_d += bottom[3];

        cost = 0;
    };

    bool isInEndState()
    {
        return room_a == "AA" && room_b == "BB" && room_c == "CC" && room_d == "DD";
    }

    void applyMove(Move m)
    {
        char c = getChar(m.from, m.from_loc);
        int dist = getDistanceOfMove(m);
        cost += COST[c] * dist;
        // cout << "cost: " << cost << endl;

        putChar(m.from, m.from_loc, '.');
        putChar(m.to, m.to_loc, c);
    }

    vector<Move> getValidMoves()
    {
        vector<Move> valid_hallway_moves = getValidHallwayMoves();
        // cout << valid_hallway_moves.size() << endl;
        vector<Move> valid_room_moves = getValidRoomMoves();
        // cout << valid_room_moves.size() << endl;

        vector<Move> valid_moves = valid_hallway_moves;
        valid_moves.insert(valid_moves.end(), valid_room_moves.begin(), valid_room_moves.end());

        return valid_moves;
    }

    string hash()
    {
        return hallway + room_a + room_b + room_c + room_d;
    }

private:
    int getDistanceOfMove(Move m)
    {
        int dist = 0;

        if (m.from == HALLWAY)
        {
            dist += m.to_loc;
            dist += getHallwayDistance(m.to, m.from_loc);
        }
        else
        { // from == ROOM_X
            dist += m.from_loc;
            dist += getHallwayDistance(m.from, m.to_loc);
        }

        return dist;
    }

    int getHallwayDistance(Location room, int hallway_loc)
    {
        int s;
        int t = hallway_loc;

        if (room == ROOM_A)
            s = 2;
        else if (room == ROOM_B)
            s = 4;
        else if (room == ROOM_C)
            s = 6;
        else // room == ROOM_D
            s = 8;

        return abs(s - t);
    }

    char getChar(Location loc, int i)
    {
        if (loc == HALLWAY)
            return hallway[i];
        else if (loc == ROOM_A)
            return room_a[i];
        else if (loc == ROOM_B)
            return room_b[i];
        else if (loc == ROOM_C)
            return room_c[i];
        else // if (loc == ROOM_D)
            return room_d[i];
    }

    void putChar(Location loc, int i, char c)
    {
        if (loc == HALLWAY)
            hallway[i] = c;
        else if (loc == ROOM_A)
            room_a[i] = c;
        else if (loc == ROOM_B)
            room_b[i] = c;
        else if (loc == ROOM_C)
            room_c[i] = c;
        else // if (loc == ROOM_D)
            room_d[i] = c;
    }

    vector<Move> getValidRoomMoves()
    {
        vector<Move> valid_moves;

        vector<Location> rooms = {ROOM_A, ROOM_B, ROOM_C, ROOM_D};
        vector<int> hallway_locs = {0, 1, 3, 5, 7, 9, 10};

        for (Location room : rooms)
        {
            Move m;
            m.from = room;
            m.to = HALLWAY;
            string r = getRoom(room);

            if (room == ROOM_A && (r == "AA" || r == ".A"))
                continue;
            if (room == ROOM_B && (r == "BB" || r == ".B"))
                continue;
            if (room == ROOM_C && (r == "CC" || r == ".C"))
                continue;
            if (room == ROOM_D && (r == "DD" || r == ".D"))
                continue;

            for (int i = 0; i < 2; ++i)
            {
                m.from_loc = i;
                if (r[i] != '.')
                {
                    for (int t : hallway_locs)
                    {
                        m.to_loc = t;
                        if (isValidMove(m))
                            valid_moves.push_back(m);
                    }
                }
            }
        }

        return valid_moves;
    }

    vector<Move> getValidHallwayMoves()
    {
        vector<Move> valid_moves;

        for (int i = 0; i < hallway.length(); ++i)
        {
            Move m;
            m.from = HALLWAY;
            m.from_loc = i;

            if (hallway[i] == 'A')
                m.to = ROOM_A;
            else if (hallway[i] == 'B')
                m.to = ROOM_B;
            else if (hallway[i] == 'C')
                m.to = ROOM_C;
            else if (hallway[i] == 'D')
                m.to = ROOM_D;
            else // hallway[i] == '.'
                continue;

            m.to_loc = 0;
            if (isValidMove(m))
                valid_moves.push_back(m);

            m.to_loc = 1;
            if (isValidMove(m))
                valid_moves.push_back(m);
        }

        return valid_moves;
    }

    bool isValidMove(Move m)
    {
        vector<bool> checks = {
            targetHasSpace(m.to, m.to_loc),
            targetMatchesType(m.from, m.from_loc, m.to),
            pathIsUnobstructed(m.from, m.from_loc, m.to, m.to_loc),
            targetWontBlockOther(m.to, m.to_loc),
        };
        // for (bool check : checks)
        // {
        //     cout << "check: " << check << endl;
        // }
        int ok_check_count = accumulate(checks.begin(), checks.end(), 0);
        // cout << "ok_check_count: " << ok_check_count << endl;
        // cout << "check_size: " << checks.size() << endl;
        // cout << "--------" << endl;
        return ok_check_count == checks.size();
    }

    /**
     * 
     * 012345678910
     * OOOOOOOOOOO
     *   A B C D  0
     *   A B C D  1
     * 
     */
    bool pathIsUnobstructed(Location from, int from_loc, Location to, int to_loc)
    {
        int s;
        int t;
        if (from == HALLWAY)
        {
            s = from_loc;

            if (to == ROOM_A)
                t = 2;
            else if (to == ROOM_B)
                t = 4;
            else if (to == ROOM_C)
                t = 6;
            else // to == ROOM_D
                t = 8;

            if (isBlockedOnHallway(s, t, from))
            {
                // cout << "blocked on hallway when going to room" << endl;
                return false;
            }

            return canEnterRoom(to, to_loc);
        }
        else
        { // from == ROOM_X
            if (to == ROOM_A)
                s = 2;
            else if (to == ROOM_B)
                s = 4;
            else if (to == ROOM_C)
                s = 6;
            else // to == ROOM_D
                s = 8;

            t = to_loc;

            if (isBlockedOnHallway(s, t, from))
            {
                // cout << "blocked on hallway when going to hallway" << endl;
                return false;
            }

            return canExitRoom(from, from_loc);
        }
    }

    string getRoom(Location room)
    {
        if (room == ROOM_A)
            return room_a;
        else if (room == ROOM_B)
            return room_b;
        else if (room == ROOM_C)
            return room_c;
        else //if (room == ROOM_D)
            return room_d;
    }

    bool canExitRoom(Location room, int location)
    {
        string r = getRoom(room);
        if (location == 0)
            return true;
        else // location == 1
            return r[0] == '.';
    }

    bool canEnterRoom(Location room, int location)
    {
        string r = getRoom(room);
        if (location == 0)
            return r[0] == '.';
        else // location == 1
            return r[0] == '.' && r[1] == '.';
    }

    bool isBlockedOnHallway(int s, int t, Location from)
    {
        // cout << "s: " << s << " t: " << t << endl;
        int dir = s < t ? 1 : -1;

        if (from == HALLWAY)
            s += dir;

        // cout << "'";
        for (int i = s; i != t; i += dir)
        {
            // cout << hallway[i];
            if (hallway[i] != '.')
            {
                // cout << "' blocked on i=" << i << endl;
                // cout << ". ?== " << hallway[i] << " --> " << (hallway[i] == '.') << endl;
                return true;
            }
        }

        // cout << "'" << endl;
        return false;
    }

    bool targetMatchesType(Location from, int from_loc, Location to)
    {
        if (to == HALLWAY)
            return true;

        char type;

        if (from == HALLWAY)
            type = hallway[from_loc];
        else if (from == ROOM_A)
            type = room_a[from_loc];
        else if (from == ROOM_A)
            type = room_b[from_loc];
        else if (from == ROOM_A)
            type = room_c[from_loc];
        else // if (from == ROOM_D)
            type = room_d[from_loc];

        if (type == 'A')
            return to == ROOM_A;
        if (type == 'B')
            return to == ROOM_B;
        if (type == 'C')
            return to == ROOM_C;
        else // (type == 'D')
            return to == ROOM_D;
    }

    bool targetHasSpace(Location to, int location)
    {
        if (to == HALLWAY)
            return hallway[location] == '.';
        else if (to == ROOM_A)
            return room_a[location] == '.';
        else if (to == ROOM_B)
            return room_b[location] == '.';
        else if (to == ROOM_C)
            return room_c[location] == '.';
        else // if (to == ROOM_D)
            return room_d[location] == '.';
    }

    bool targetWontBlockOther(Location to, int location)
    {
        if (to == HALLWAY)
            return true;
        else
        {
            if (location == 1)
                return true;
            else
            {
                if (to == ROOM_A)
                    return room_a[1] == 'A';
                else if (to == ROOM_B)
                    return room_b[1] == 'B';
                else if (to == ROOM_C)
                    return room_c[1] == 'C';
                else // if (to == ROOM_D)
                    return room_d[1] == 'D';
            }
        }
    }
};
ostream &operator<<(ostream &os, const GameState &gs)
{
    os << "|-----------|" << endl;
    os << "|" << gs.hallway << "|" << endl;
    os << "|-|" << gs.room_a[0] << "|" << gs.room_b[0] << "|" << gs.room_c[0] << "|" << gs.room_d[0] << "|-|" << endl;
    os << "  |" << gs.room_a[1] << "|" << gs.room_b[1] << "|" << gs.room_c[1] << "|" << gs.room_d[1] << "|" << endl;
    os << "  |-------|" << endl;
    return os;
}

int dfs(GameState gs, Move move, int depth)
{
    if (depth >= 12)
        return INT32_MAX;
    // cout << "-------" << endl;
    gs.applyMove(move);
    // cout << gs << endl;

    if (gs.isInEndState())
    {
        // cout << gs << endl;
        // cout << "endstate ";
        if (MEMO.find(gs.hash()) == MEMO.end())
        {
            // cout << "and inserting: " << gs.cost << endl;
            MEMO[gs.hash()] = gs.cost;
            return MEMO[gs.hash()];
        }
        else
        {
            if (gs.cost < MEMO[gs.hash()])
            {
                // cout << "and updating: " << gs.cost << endl;
                MEMO[gs.hash()] = gs.cost;
            }
            return MEMO[gs.hash()];
        }

        // return MEMO[gs.hash()];
        // cout << "                                          ERROR" << endl;
        return -1;
    }

    if (MEMO.find(gs.hash()) != MEMO.end())
    {
        // cout << gs << endl;
        // cout << "memo: " << MEMO[gs.hash()] << endl;
        return MEMO[gs.hash()];
    }

    vector<Move> valid_moves = gs.getValidMoves();
    int optimal_cost = INT32_MAX;

    for (Move &m : valid_moves)
        optimal_cost = min(optimal_cost, dfs(gs, m, depth + 1));

    // cout << "end of function: " << optimal_cost << endl;
    MEMO[gs.hash()] = optimal_cost;
    return optimal_cost;
}

int dfs_start(GameState gs)
{
    // cout << "STARTING" << endl;
    vector<Move> valid_moves = gs.getValidMoves();
    int optimal_cost = INT32_MAX;

    for (Move m : valid_moves)
        optimal_cost = min(optimal_cost, dfs(gs, m, 1));

    return optimal_cost;
}

int test_endstate()
{
    GameState gs("ABCD", "ABCD");
    return gs.isInEndState();
}

void test_simple()
{
    GameState gs("BACD", "ABCD");
    cout << dfs_start(gs) << endl;
}

void test_hallway_moves()
{
    GameState gs(".BCD", "ABCD");
    gs.hallway[0] = 'A';
    cout << gs << endl;
    dfs_start(gs);
}

int main()
{
    // const rlim_t kStackSize = ulong(8) * 1024 * 1024 * 1024; // 4GB
    // struct rlimit r1;
    // getrlimit(RLIMIT_STACK, &r1);
    // r1.rlim_cur = kStackSize;
    // setrlimit(RLIMIT_STACK, &r1);

    // test_simple();
    // test_hallway_moves();
    // cout << "Can recognize endstate: " << test_endstate() << endl;

    string top, bottom;
    cin >> top >> bottom;

    GameState gs(top, bottom);
    cout << gs << endl;
    cout << INT32_MAX << endl;
    cout << dfs_start(gs) << endl;
}