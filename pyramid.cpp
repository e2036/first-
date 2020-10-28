
#include<iostream>
#include<stdio.h>
#include<ctype.h>
int main(){
    int count;
    int kuuhaku;
    int asutarisuku=1;
    int asutarisukucount=0;
    char hajime;
    char hyouji;

    std::cout<<"何段にしますか";
    std::cin>>count;


    while(!(islower(hajime))){
    std::cout<<"どのアルファベットから始めますか？";
    std::cin>>hajime;
    if(islower(hajime)){
    }else{
    std::cout<<"小文字のアルファベットを入力してください";
    std::cin>>hajime;
    }

    }
    kuuhaku=count-1;
    for(int i=0;i<count;i++){

        for(int j=0; j<kuuhaku; j++){
            std::cout<<" ";
        }
        for(int j=0; j<asutarisuku; j++){
         hyouji = hajime + asutarisukucount%26;
        if( islower(hyouji)){
         printf("%c",hyouji) ;
         asutarisukucount++;
        }
        else{
            asutarisukucount=asutarisukucount-26;
            hyouji=hajime+ asutarisukucount%26;
            printf("%c",hyouji);
            asutarisukucount++;
        }
        }
        std::cout<<"\n";
        kuuhaku=kuuhaku-1;
        asutarisuku=asutarisuku+2;
    }
}
