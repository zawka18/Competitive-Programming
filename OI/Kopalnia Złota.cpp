#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int R = (1 << 16);
ll drzewo[R * 2];
ll przep[R * 2];
vector<vector<int>> punkty_od_dolu;

void przepchnij(int akt_wie, int l, int r){
    przep[l] += przep[akt_wie];
    przep[r] += przep[akt_wie];

    drzewo[l] += przep[akt_wie];
    drzewo[r] += przep[akt_wie];

    przep[akt_wie] = 0;
}

void zmien(int akt_wie, int pocz_odp, int kon_odp, int pocz_pyt, int kon_pyt, ll val){
    if (pocz_odp > kon_pyt || kon_odp < pocz_pyt) {
        return;
    } else if (pocz_pyt <= pocz_odp && kon_odp <= kon_pyt){
        drzewo[akt_wie] += val;
        przep[akt_wie] += val;
    } else {
        int l, r, srodek;
        l = akt_wie * 2;
        r = akt_wie * 2 + 1;
        srodek = (pocz_odp + kon_odp) / 2;
        przepchnij(akt_wie, l, r);
        zmien(l, pocz_odp, srodek, pocz_pyt, kon_pyt, val);
        zmien(r, srodek + 1, kon_odp, pocz_pyt, kon_pyt, val);
        drzewo[akt_wie] = max(drzewo[l], drzewo[r]);
    }
}

ll odpowiedz(int akt_wie, int pocz_odp, int kon_odp, int pocz_pyt, int kon_pyt) {
    if (pocz_odp > kon_pyt || kon_odp < pocz_pyt) {
        return 0;
    } else if (pocz_pyt <= pocz_odp && kon_odp <= kon_pyt){
        return drzewo[akt_wie];
    } else {
        int l, r, srodek;
        l = akt_wie * 2;
        r = akt_wie * 2 + 1;
        srodek = (pocz_odp + kon_odp) / 2;
        przepchnij(akt_wie, l, r);
        return max(odpowiedz(l, pocz_odp, srodek, pocz_pyt, kon_pyt),
        odpowiedz(r, srodek + 1, kon_odp, pocz_pyt, kon_pyt));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, w;
    cin >> s >> w;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x += 30000;
        y += 30000;
        punkty_od_dolu.push_back({y, -1, x}); 
        punkty_od_dolu.push_back({y + w, 1, x});
    }

    sort(punkty_od_dolu.begin(), punkty_od_dolu.end());

    ll max_wyn = 0;
    for (int i = 0; i < n * 2; i++){
        int akt_x = punkty_od_dolu[i][2];
        int typ = punkty_od_dolu[i][1];
        int now_x = akt_x + s;
        if (typ == 1){
            zmien(1, 0, R - 1, akt_x, now_x, -1);
        } else {
            zmien(1, 0, R - 1, akt_x, now_x, 1);
        }

        max_wyn = max(max_wyn, odpowiedz(1, 0, R - 1, 0, R - 1));
    }

    cout << max_wyn << '\n';

    return 0;
}
