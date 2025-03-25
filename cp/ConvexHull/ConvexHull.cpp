#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::sort;

typedef long long ld;
const ld eps = 1e-9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }

     ld cross(pt o) const { return x*o.y - y*o.x; }
};

vector<pt> convexHull(vector<pt>& pts, bool sorted = false){
  if(!sorted) sort(begin(pts),end(pts));
  vector<pt> h;
  h.reserve(pts.size() + 1);
  for(int it = 0; it < 2; it++){
    int start = h.size();
    for(pt& c : pts){
      while((int)h.size() >= start + 2){
        pt a = h[h.size()-2], b = h.back();
        // '>=' pra nao descartar pontos colineares
        if((b-a).cross(c-a) >= 0) break; 
        h.pop_back();
      }
      h.push_back(c);
    }
    reverse(begin(pts),end(pts));
    h.pop_back();
  }
  if(h.size() == 2 && h[0] == h[1]) h.pop_back();
  return h;
}

int main() {
    int n;
    std::cin >> n;

    long long x, y;
    vector<pt> points(n);
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        points[i] = pt(x,y);
    }

    vector<pt> results = convexHull(points);
    std::cout << results.size() << std::endl;
    for(int i = 0; i < results.size(); i++){
        pt point = results[i];
        std::cout << point.x << " " << point.y << std::endl;
    }
}