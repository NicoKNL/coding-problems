#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long T;
typedef pair<T, T> Point;

T calculateAreaBetweenPoints(const Point &a, const Point &b)
{
	return abs(b.x - a.x) * abs(b.y - a.y);
}

T calculateBoundingBox(vector<Point> &points)
{
	sort(points.begin(), points.end());

	return calculateAreaBetweenPoints(points[0], points[points.size() - 1]);
}

T calculateArea(const multiset<T> &xs, const multiset<T> &ys)
{
	T xmin = *min_element(xs.begin(), xs.end());
	T xmax = *max_element(xs.begin(), xs.end());

	T ymin = *min_element(ys.begin(), ys.end());
	T ymax = *max_element(ys.begin(), ys.end());

	return abs(xmax - xmin) * abs(ymax - ymin);
}

T calculateOptimalHorizontalSplitArea(vector<Point> &points)
{
	sort(points.begin(), points.end());

	multiset<T> xs_left;
	multiset<T> xs_right;

	multiset<T> ys_left;
	multiset<T> ys_right;

	// Initialize ys right
	for (const auto &p : points)
	{
		xs_right.insert(p.x);
		ys_right.insert(p.y);
	}

	// Step through and expand left
	T optimal = LLONG_MAX;
	for (const auto &p : points)
	{
		xs_right.erase(xs_right.find(p.x));
		xs_left.insert(p.x);

		ys_right.erase(ys_right.find(p.y));
		ys_left.insert(p.y);

		T area_left = calculateArea(xs_left, ys_left);
		T area_right = calculateArea(xs_right, ys_right);

		optimal = min(optimal, area_left + area_right);
	}
	return optimal;
}

void solve()
{
	int point_count;
	cin >> point_count;

	vector<Point> points;

	for (int i = 0; i < point_count; ++i)
	{
		T px, py;
		cin >> px >> py;

		Point p = Point(px, py);
		points.emplace_back(p);
	}

	T bbox_area = calculateBoundingBox(points);
	T hsplit_area = calculateOptimalHorizontalSplitArea(points);

	for (auto &p : points)
	{
		swap(p.x, p.y);
	}
	T vsplit_area = calculateOptimalHorizontalSplitArea(points);

	vector<T> results = {bbox_area, hsplit_area, vsplit_area};
	cout << *min_element(results.begin(), results.end()) << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
}