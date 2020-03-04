#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    ifstream ifs1(argv[2]), ifs2(argv[3]);  // 入力ファイル名

    ofstream ofs1(argv[5]), ofs2(argv[6]), ofs3(argv[7]);  // 出力ファイル名


    if(ifs1.fail()){ // 入力ファイル読み込み失敗時のエラーコード
        cerr << "Failed to open file." << endl;
        return -1;
    }
 
    bool ok = false;  // while文終了フラグ(ファイル読み込みが末尾までいったらtrueにする)

    string str1, str2;
    getline(ifs1, str1);
    getline(ifs2, str2);

    while(true){
        if(str1 == "" || str2 == "") break; // ファイルの末尾まで来たら終了
        string S1head = str1.substr(1,22);
        string S2head = str2.substr(1,22);
        if(S1head == S2head){  // 読み込んだリードがpaired-endsリードの場合
            for(int k = 0;k < 4; k++){ // 4行をそれぞれファイルに出力する
                ofs1 << str1 << endl;
                ofs2 << str2 << endl;
                if(!getline(ifs1, str1) || !getline(ifs2, str2)) ok = true;  // ファイルの末尾まで来たら終了
            }
        }
        else{  // 読み込んだリードがpaired-endsリードの場合、辞書順で前のファイルの方のみをofs3に出力
            if(str1 > str2){  
                for(int k = 0;k < 4; k++){ // 4行をofs3に出力
                    ofs3 << str2 << endl;
                    if(!getline(ifs2, str2)) ok = true; // ファイルの末尾まで来たら終了
                }
            }
            else{
                for(int k = 0;k < 4; k++){ // 4行をofs3に出力
                    ofs3 << str1 << endl;
                    if(!getline(ifs1, str1)) ok = true; // ファイルの末尾まで来たら終了
                }
            }
        }
        if(ok) break; // 終了フラグがたっていたらwhile文終了
    }

    ofs1.close();
    ofs2.close();

}
