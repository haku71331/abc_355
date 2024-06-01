#include <iostream>
#include <vector>

using namespace std;

bool hasConsecutiveElements(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    C.reserve(A.size() + B.size());

    // 数列Aと数列BをマージしてCを生成
    size_t i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            C.push_back(A[i]);
            ++i;
        } else {
            C.push_back(B[j]);
            ++j;
        }
    }
    while (i < A.size()) {
        C.push_back(A[i]);
        ++i;
    }
    while (j < B.size()) {
        C.push_back(B[j]);
        ++j;
    }

    // C内で連続する要素があるかどうかをチェック
    for (size_t k = 1; k < C.size(); ++k) {
        if (C[k] == C[k - 1] + 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < M; ++j) {
        cin >> B[j];
    }

    if (hasConsecutiveElements(A, B)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
