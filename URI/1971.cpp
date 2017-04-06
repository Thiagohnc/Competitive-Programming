/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1971/ */

#include <bits/stdc++.h>
#define MAXN 5000
#define f first
#define s second
#define mp make_pair

using namespace std;

int cmp_double(double a, double b, const double eps = 1e-9) {
    if(a + eps > b && b + eps > a) return 0;
    if(a - eps > b) return -1;
    return 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+ (const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    double operator% (const Point &o) const { return x * o.y - y * o.x; }
    bool operator== (const Point &o) const {
        return cmp_double(x, o.x) == 0 && cmp_double(y, o.y) == 0;
    }
    bool operator< (const Point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
};

Point p[MAXN], h[MAXN];
int n, k;

double ccw(Point p, Point q, Point r) {
    return cmp_double((q - p) % (r - p), 0.0);
}

double dist(Point a, Point b) {
    return sqrt(pow(a.y - b.y,2) + pow(a.x - b.x, 2));
}

void convex_hull() {
    sort(p, p+n);
    k = 0;
    h[k++] = p[0];
    for(int i = 1; i < n; i++) {
        if(i != n-1 && ccw(p[0], p[n-1], p[i]) >= 0) continue;
        while(k > 1 && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    for(int i = n-2, lim = k; i >= 0; i--) {
        if(i != 0 && ccw(p[n-1], p[0], p[i]) >= 0) continue;
        while(k > lim && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    k--;
}

void parado(void) {
    printf("\\O/\n | \n/ \\\n");
}

void correndo() {
    printf(" O>\n<| \n/ >\n");
}

bool col() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int  k =0; k < n; k++) {
                if(i != j && j != k && i != k) if(ccw(p[i], p[j], p[k]) != 0) return false;
            }
        }
    }
    return true;
}

typedef Point Vector;

int main(void) {
    Point c;
        n = 5;
        for(int i = 0; i < 5; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        if(col()) {
            correndo();
            return 0;
        }
        c = p[4];
        convex_hull();
        for(int i = 0; i < k+1; i++) {
            if(h[i] == c) {
                correndo();
                return 0;
            }
        }
        parado();

    return 0;
}
