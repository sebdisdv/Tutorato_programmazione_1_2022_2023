#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(int argc,char** argv) {
    if(argc!=3){
        cout << "USAGE <input> <output>";
        exit(1);
    }
    fstream in,out;
    in.open(argv[1],ios::in);
    if(in.fail()){
        cout << "IMPOSSIBILE APRIRE IL FILE DI INPUT";
        exit(1);
    }
    out.open(argv[2],ios::out);
    if(out.fail()){
        cout << "IMPOSSIBILE APRIRE IL FILE DI OUTPUT";
        in.close();
        exit(1);
    }
    char words[100][101]; // 100 is the max patterns and 101 is the max len of a word (+\0)
    char word[101];
    int occ[100]={};
    int how_many=0;
    bool flag;
    bool is_string;
    while(in >> word){
        //checks wheter it is a string
        is_string=true;
        for(int i=0;word[i]!='\0';i++){
            if(word[i]>'z' || word[i]<'a'){
                is_string=false;
            }
        }
        //now string is correct
        if(is_string){
            //cout << word << endl;
            flag= true;
            for(int i=0;i<how_many && flag;i++){
                if(!strcmp(words[i],word)){
                    flag=false;
                    occ[i]++;
                }
            }
            if(flag){
                strcpy(words[how_many],word);
                how_many++;
            }
        }
    }
    for(int i=0;i<how_many;i++){
        out << words[i] << ": " << occ[i]+1 << endl;
    }
    in.close();
    out.close();
    return 0;
}
