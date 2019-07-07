/*
    if(same(x, y) == false) uni(x, y);
*/
struct DSU {
    int p[maxn], sz[maxn];
    
    DSU() {
        for(int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1;
    }    
    
    int find(const int &x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    bool same(int &x, int &y) {
        x = find(x), y = find(y);
        return x == y;
    }
    void uni(const int &x, const int &y) {
        // x, y must be parent
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
};
