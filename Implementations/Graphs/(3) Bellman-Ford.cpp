// https://open.kattis.com/problems/shortestpath3

const ll INF = 1e18;

int n,m,q,s,bad[1000];
vector<pair<pii,int>> edge;
ll dist[1000];

void solve() {
    edge.clear();
    F0R(i,n) dist[i] = INF, bad[i] = 0;
    dist[s] = 0;
    F0R(i,m) {
        int u,v,w; cin >> u >> v >> w;
        edge.pb({{u,v},w});
    }    
    F0R(i,n) for (auto a: edge) if (dist[a.f.f] < INF) dist[a.f.s] = min(dist[a.f.s], dist[a.f.f]+a.s); 
    for (auto a: edge) if (dist[a.f.f] < INF) if (dist[a.f.s] > dist[a.f.f]+a.s) bad[a.f.s] = 1;
    F0R(i,n) for (auto a: edge) if (bad[a.f.f]) bad[a.f.s] = 1;
    
    F0R(i,q) {
        int x; cin >> x;
        if (bad[x]) cout << "-Infinity\n";
        else if (dist[x] == INF) cout << "Impossible\n";
        else cout << dist[x] << "\n";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	while (cin >> n >> m >> q >> s) {
	    if (n+m+q+s == 0) break;
	    solve();
	}
}

// read!
// ll vs. int!