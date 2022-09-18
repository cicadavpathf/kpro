#include <iostream>
#include <cmath>

using namespace std;

struct V {
    double x;
    double y;
};

const double rad60d = 60.0 * (M_PI / 180.0);

void kochCurve(V p1, V p2, int n) {
    if (n <= 0) return;

    V s = {
        (p1.x * 2.0 + p2.x) / 3.0,
        (p1.y * 2.0 + p2.y) / 3.0
    };

    V t = {
        (p1.x + p2.x * 2.0) / 3.0,
        (p1.y + p2.y * 2.0) / 3.0
    };

    V st = { t.x - s.x, t.y - s.y };

    V su = {
        st.x * cos(rad60d) - st.y * sin(rad60d),
        st.x * sin(rad60d) + st.y * cos(rad60d)
    };

    V u = { s.x + su.x, s.y + su.y };

    kochCurve(p1, s, n - 1);

    printf("%lf %lf\n", s.x, s.y);
    kochCurve(s, u, n - 1);

    printf("%lf %lf\n", u.x, u.y);
    kochCurve(u, t, n - 1);

    printf("%lf %lf\n", t.x, t.y);
    kochCurve(t, p2, n - 1);
}

int main() {
    int n;
    cin >> n;

    V startPoint = { 0.0, 0.0 };
    V endPoint = { 100.0, 0.0 };

    printf("%lf %lf\n", startPoint.x, startPoint.y);

    kochCurve(startPoint, endPoint, n);

    printf("%lf %lf\n", endPoint.x, endPoint.y);
}
