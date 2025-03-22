#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>

using std::fabs;
using std::vector;

#define EPS 1e-9
#define INF 1e9

struct point {
	double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

	bool operator <(point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec {
	double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); // convert 2 points to vector a->b
}

vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s); // nonnegative s = [<1 .. 1 .. >1]
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
	return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { 
        c = point(a.x, a.y); // closer to a
        return dist(p, a); // Euclidean distance between p and a 
    }
    if (u > 1.0) { 
        c = point(b.x, b.y); // closer to b
        return dist(p, b); // Euclidean distance between p and b 
    } 
    return distToLine(p, a, b, c);
}

int main() {
	double x, y;
	int n;

	while (std::cin >> x >> y >> n) {
		point m(x, y);
        vector<point> rails(n+1);

		for (int i = 0; i < n + 1; i++) {
            std::cin >> x >> y;
			rails[i] = point(x, y);
		}

		double minDist = INF;
		point result(INF, INF), tmpResult(INF, INF);
		for (int i = 0; i < n; i++) {
			double distLine = distToLineSegment(m, rails[i], rails[i + 1], tmpResult);
			if (distLine < minDist) {
				minDist = distLine;
				result = tmpResult;
			}
		}
        std::cout << std::fixed << std::setprecision(4);
        std::cout << result.x << std::endl << result.y << std::endl;
	}
}