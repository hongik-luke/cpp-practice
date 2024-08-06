#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string st;
        cin>>st;
        int front = 0, back = st.length() - 1;
        int check = 0;

        while (front < back) {
            if (st[front] == st[back]) {
                front++;
                back--;
                continue;
            }

            // 뒷 문자 제거했는데 같을 때, 나머지로 회문 되는지 확인
            if (st[front] == st[back - 1]) {
                string temp = st.substr(front, back - front);
                string reversed_temp = string(temp.rbegin(), temp.rend());
                if (temp == reversed_temp) {
                    check = 1;
                    break;
                }
            }

            // 앞 문자 제거했는데 같으면
            if (st[front + 1] == st[back]) {
                string temp = st.substr(front + 1, back - front);
                string reversed_temp = string(temp.rbegin(), temp.rend());
                if (temp == reversed_temp) {
                    check = 1;
                    break;
                }
            }

            check = 2;
            break;
        }

        cout << check << endl;
    }

    return 0;
}