#include <iostream>
#include <fstream>

using namespace std;

int n;
int so_0 = 0; ///đếm số lượng số 0
int ma = 0, mi = 9999999; ///phần tử nhỏ nhất và lớn nhất
int l[20000006]; ///độ dài dài liên tục dài nhất đến số l[i]
int dist[2000006]; ///khoảng trông để cần lấp vào để tạo thành chuỗi liên tục từ 1 -> i

void Init() { for (int i = 1; i <= 2000006; i++) l[i] = 0; }

void Enter() {
    freopen("LSEQ.INP", "r", stdin);
    freopen("LSEQ.OUT", "w", stdout);
    cin>>n;
    int temp;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        if (temp==0) so_0++;
        else {
            temp+=1000001;
            ma=max(ma, temp);
            mi=min(mi, temp);
            l[temp]=1;
        }
    }
}

void DP() {
    int i;
    l[mi-1]=0;
    dist[mi-1]=0;
    for (i=mi;i<=ma;i++) {
        if (l[i]==1) {
            l[i]=l[i-1]+1;
            dist[i]=dist[i-1];
        }
        else dist[i]=dist[i-1]+1;
    }
}

void Print() {
    if (n-so_0<2) {
        cout<<n;
        return;
    }

    int ma_res;
    int diemdau = mi, diemcuoi;
    int kt = 0;
    for (diemcuoi = mi; diemcuoi <= ma; diemcuoi++) {
        if (dist[diemcuoi] - dist[diemdau - 1] <= so_0) {
            ma_res = diemcuoi - diemdau + 1;
            kt = dist[diemcuoi] - dist[diemdau - 1];
        }
        else {
            diemcuoi--;
            break;
        }
    }

    //cout << diemdau - 1000001 << " " << diemcuoi - 1000001;

    for (int i = diemcuoi; i <= ma; i++) {
        diemcuoi++;
        if (dist[diemcuoi]-dist[diemdau-1]==so_0) ma_res++;
        else diemdau++;
    }
    cout<<ma_res+so_0-kt;
}

void TestOut() {
    for (int i = mi; i <= ma; i++) {
        cout<<i-1000001<<" ";
        cout<<l[i] <<" "<<dist[i] << endl;
    }
}

int main() {
    Init();
    Enter();
    DP();
    Print();
    return 0;
}
