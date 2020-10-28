#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

	int players=0;
	int clear=0;
	int wolfcount=0;
	int uranaicount=0;
	int foxcount=0;
	int kisicount=0;
	int playerscount=0;
	int jobcheck=0;
	int uranaisaki=0;
	int touhyousaki=0;
	int touhyoukekka=0;
	int syuugekisaki=0;
	int syuugekikekka=0;
	int mamorisaki=0;
	int kyousincount=0;
	int murabitojinnei=0;
	int jinroujinnei=0;
	srand(time(NULL))  ;
	//プレイ人数入力
	std::cout<<"プレイ人数を入力してください\n";
	while(players<=3){
		std::cin>>players;
		if(players<=3){
			std::cout<<"その人数では遊べません\n"<<
				"もう一度入力してください\n";
		}

	}

	int player[players];

	int touhyou[players];
	for(int i=0;i<players; i++){
		touhyou[i]=0;
	}
	int syuugeki[players];
	for(int i=0;i<players; i++){
		syuugeki[i]=0;
	}
	int mamori[players];
	for(int i=0;i<players; i++){
		mamori[i]=0;
	}
	int die[players];
	for(int i=0;i<players; i++){
		die[i]=0;
	}
	int job[players];
	for(int i=0;i<players; i++){
		job[i]=0;
	}
	cv::Mat img[players];

	system("clear");


	//配役決定
	while(jobcheck==0) {
		wolfcount=0;
		uranaicount=0;
		foxcount=0;
		kisicount=0;
		kyousincount=0;
		murabitojinnei=0;
		jinroujinnei=0;
		for(int i=0; i<players; i++){

			player[i]=(int)rand()%7+1;
			job[i]=player[i];
			if(player[i]==3){
				wolfcount++;
			}else if(player[i]==2){
				uranaicount++;
			}else if(player[i]==5){
				foxcount++;
			}else if(player[i]==6){
				kisicount++;
			}else if(player[i]==7){
				kyousincount++;
			}
			if(player[i]==1||player[i]==2||player[i]==6){
				murabitojinnei++;
			}else if(player[i]==3||player[i]==4||player[i]==7){
				jinroujinnei++;
			} 
			if(wolfcount <= players/3 && wolfcount > 0 && uranaicount <= players/3 && uranaicount > 0 &&
					foxcount <= players/5  && kisicount <= players/4 && kyousincount <= players/4 && jinroujinnei+1 < murabitojinnei ){
				jobcheck=1;
			}
		}
	}
	wolfcount=0;
	uranaicount=0;
	foxcount=0;
	kisicount=0;
	kyousincount=0;
	//役職発表
	for(int i=0;i<players; i++){
		std::cout <<"役職の発表をしますプレイヤー"<<i+1<<"は準備ができたら０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

		if(player[i]==1){
			std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
			img[i] = cv::imread("murabito.jpg");

			cv::imshow("村人", img[i] );
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==2){
			std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
			img[i]  = cv::imread("uranai.jpg");
			cv::imshow("占い師",  img[i] );
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==3){
			std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
			img[i] = cv::imread("jinro.jpg");
			cv::imshow("人狼", img[i]);
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==4){
			std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
			img[i] = cv::imread("kyoujin.jpg");
			cv::imshow("狂人", img[i]);
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==5){
			std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
			img[i] = cv::imread("youko.jpg");
			cv::imshow("妖狐", img[i]);
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==6){
			std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
			img[i] = cv::imread("kisi.jpg");
			cv::imshow("騎士", img[i]);
			cv::waitKey(500);
			cv::destroyAllWindows();
		}else if(player[i]==7){
			std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
			img[i] = cv::imread("kyousin.jpg");
			cv::imshow("狂信者", img[i]);
			cv::waitKey(500);
			cv::destroyAllWindows();
		}


		std::cout << "交代するために０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

	}
	//初日夜行動	
	for(int i=0;i<players; i++){
		std::cout <<"夜の行動をします。プレイヤー"<<i+1<< "は準備ができたら０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

		if(player[i]==1){
			std::cout<<"村人に夜の行動はありません\n";
		}else if(player[i]==2){
			std::cout<<"占いたいプレイヤーの番号を入力してください\n";

			while(uranaisaki>players||uranaisaki-1<0||
					uranaisaki-1==i||player[uranaisaki-1]==0){
				std::cin>>uranaisaki;
				if(uranaisaki>players||uranaisaki-1<0 ||uranaisaki-1==i||player[uranaisaki-1]==0){
					std::cout<<"そのプレイヤーを占うことができません\n"<<"もう一度入力してください";
				}
			}
			if(player[uranaisaki-1]==3){
				std::cout<<"プレイヤー"<<uranaisaki<<"は人狼です\n";
			}else if(player[uranaisaki-1]==5){
				std::cout<<"プレイヤー"<<uranaisaki<<"は人狼ではありません\n";
				player[uranaisaki-1]=0;
				die[uranaisaki-1]=1;
			}else{
				std::cout<<"プレイヤー"<<uranaisaki<<"は人狼ではありません\n";
			}
			uranaisaki=0;
		}else if(player[i]==3){
			std::cout<<"人狼には初日の夜の行動はありません\n"<<"人狼は\n";
			for(int i=0; i<players; i++){
				if(player[i]==3){
					wolfcount++;
				}
			}
			if(wolfcount==1){
				std::cout<<"あなただけです\n";
			}else{
				for(int i=0; i<players; i++){
					if (player[i]==3){

						std::cout<<"プレイヤー"<<i+1<<"\n";
					}

				}
				std::cout<<"です\n";

			}


		}else if(player[i]==4){
			std::cout<<"狂人に夜の行動はありません\n";
		}else if(player[i]==5){
			std::cout<<"妖狐に夜の行動はありません\n";
		}else if(player[i]==6){
			std::cout<<"騎士に初日の夜の行動はありません\n";
		}else if(player[i]==7){
			std::cout<<"狂信者には夜の行動はありません\n"<<"人狼は\n";
			for(int i=0; i<players; i++){
				if (player[i]==3){

					std::cout<<"プレイヤー"<<i+1<<"\n";
				}


			}

			std::cout<<"です\n";
		}

		std::cout << "交代するために０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

	}
	//話し合い
	std::cout<<"本日の死亡者\n";
	for(int i=0; i<players; i++){
		if (die[i]==0){
		}else{
			std::cout<<"プレイヤー"<<i+1<<"\n";
		}
	}
	std::cout << "確認ができたら０以外の数字を入力してください\n";
	while(clear==0){
		std::cin>>clear;
	}
	system("clear");
	clear=0;

	for(int i=0;i<players; i++){
		die[i]=0;
	}

	while(1<2){
		std::cout<<"現在の生存者\n";
		for(int i=0;i<players; i++){

			if(player[i]==0){

			}else{
				std::cout<<"プレイヤー"<<i+1<<"\n";
			}
		}
		std::cout<<"それでは話し合いを開始してください\n"<<
			"話し合いが終了したら０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;
		//投票
		for(int i=0;i<players; i++){
			if(player[i]==0){
			}else{
				std::cout <<"投票をします。プレイヤー"<<i+1<< "は準備ができたら０以外の数字を入力してください\n";
				while(clear==0){
					std::cin>>clear;
				}
				system("clear");
				clear=0;
				std::cout<<"投票したいプレイヤーの番号を入力してください\n";

				while(touhyousaki>players||touhyousaki-1<0||
						touhyousaki-1==i||player[touhyousaki-1]==0){
					std::cin>>touhyousaki;
					if(touhyousaki>players||touhyousaki-1<0 ||touhyousaki-1==i||player[touhyousaki-1]==0){
						std::cout<<"そのプレイヤーに投票することができません\n"<<
							"もう一度入力してください";
					}
				}
				system("clear");
				touhyou[touhyousaki-1]++;
				touhyousaki=0;
			}
		}
		for(int i=0;i<players; i++){
			if(touhyou[touhyoukekka]<touhyou[i]){
				touhyoukekka=i;
			}else if(touhyou[touhyoukekka]==touhyou[i]){
				if(rand()%2==1){
					touhyoukekka=i;
				}
			}
		}
		//投票結果発表
		std::cout<<"プレイヤー"<<touhyoukekka+1<<"が処刑されました\n";
		for(int i=0;i<players; i++){
			if(player[i]==0){
			}else{
				std::cout<<"プレイヤー"<<i+1<<"  "<<touhyou[i]<<"票\n";
			}
		}
		player[touhyoukekka]=0;
		std::cout<<"次に進むため０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

		for(int i=0;i<players; i++){
			touhyou[i]=0;
		}
		touhyoukekka=0;

		wolfcount=0;
		uranaicount=0;
		foxcount=0;
		playerscount=0;

		for(int i=0; i<players; i++){
			if(player[i]>0){
				playerscount++;
			}
			if(player[i]==3){
				wolfcount++;
			}else if(player[i]==5){
				foxcount++;
			}
		}
		//勝利判定
		if(wolfcount==0){
			std::cout<<"この時点で人狼はいなくなりました\n";
			if(foxcount>0){
				std::cout<<"ですが、ここで妖狐が現れました\n";	  
				std::cout<<"妖狐陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}
				break;
			}else{
				std::cout<<"村人陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}

				break;
			}
		}
		if(wolfcount>=playerscount-wolfcount){
			std::cout<<"この時点で人狼の数が過半数を超えました\n";
			if(foxcount>0){
				std::cout<<"ですが、ここで妖狐が現れました\n";
				std::cout<<"妖狐陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}


				break;
			}else{
				std::cout<<"人狼陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}

				break;
			}
		}


		//夜行動
		for(int i=0;i<players; i++){
			if(player[i]==0){
			}else{
				std::cout <<"夜の行動をします。プレイヤー"<<i+1<< "は準備ができたら０以外の数字を入力してください\n";
				while(clear==0){
					std::cin>>clear;
				}
				system("clear");
				clear=0;

				if(player[i]==1){
					std::cout<<"村人に夜の行動はありません\n";
				}else if(player[i]==2){
					std::cout<<"占いたいプレイヤーの番号を入力してください\n";
					while(uranaisaki>players||uranaisaki-1<0||
							uranaisaki-1==i||player[uranaisaki-1]==0){
						std::cin>>uranaisaki;
						if(uranaisaki>players||uranaisaki-1<0 ||uranaisaki-1==i||player[uranaisaki-1]==0){
							std::cout<<"そのプレイヤーを占うことができません\n"<<
								"もう一度入力してください";
						}
					}
					if(player[uranaisaki-1]==3){
						std::cout<<"プレイヤー"<<uranaisaki<<"は人狼です\n";
					}else if(player[uranaisaki-1]==5){
						std::cout<<"プレイヤー"<<uranaisaki<<"は人狼ではありません\n";
						player[uranaisaki-1]=0;
						die[uranaisaki-1]=1;
					}else{
						std::cout<<"プレイヤー"<<uranaisaki<<"は人狼ではありません\n";
					}
					uranaisaki=0;
				}else if(player[i]==3){
					std::cout<<"襲撃したいプレイヤーの番号を入力してください\n";

					while(syuugekisaki>players||syuugekisaki-1<0||
							syuugekisaki-1==i||player[syuugekisaki-1]==0){
						std::cin>>syuugekisaki;
						if(syuugekisaki>players||syuugekisaki-1<0 ||syuugekisaki-1==i||player[syuugekisaki-1]==0||
								player[syuugekisaki-1]==3){
							std::cout<<"そのプレイヤーを襲撃することはできません\n"<<
								"もう一度入力してください";
						}
					}
					syuugeki[syuugekisaki-1]++;
					syuugekisaki=0;

				}else if(player[i]==4){
					std::cout<<"狂人に夜の行動はありません\n";
				}else if(player[i]==5){
					std::cout<<"妖狐に夜の行動はありません\n";
				}else if (player[i]==6){
					std::cout<<"守りたいプレイヤーの番号を入力して下さい\n";
					while(mamorisaki>players||mamorisaki-1<0||
							mamorisaki-1==i||player[mamorisaki-1]==0){
						std::cin>>mamorisaki;
						if(mamorisaki>players||mamorisaki-1<0 ||mamorisaki-1==i||player[mamorisaki-1]==0){
							std::cout<<"そのプレイヤーを守ることができません\n"<<
								"もう一度入力してください";
						}
					}
					system("clear");
					mamori[mamorisaki-1]++;
					mamorisaki=0;

				}else if(player[i]==7){
					std::cout<<"狂信者に夜の行動はありません\n";
				}


				std::cout << "交代するために０以外の数字を入力してください\n";
				while(clear==0){
					std::cin>>clear;
				}
				system("clear");
				clear=0;
			}
		}



		for(int i=0;i<players; i++){
			if(syuugeki[syuugekikekka]<syuugeki[i]){
				syuugekikekka=i;
			}else if(syuugeki[syuugekikekka]==syuugeki[i]){
				if(rand()%2==1){
					syuugekikekka=i;
				}
			}
		}
		if(player[syuugekikekka]==5||mamori[syuugekikekka]>0){
		}else{
			player[syuugekikekka]=0;
			die[syuugekikekka]=1;
		}
		//話し合い		
		std::cout<<"本日の死亡者\n";
		for(int i=0; i<players; i++){
			if (die[i]==0){
			}else{
				std::cout<<"プレイヤー"<<i+1<<"\n";
			}
		}
		std::cout << "確認ができたら０以外の数字を入力してください\n";
		while(clear==0){
			std::cin>>clear;
		}
		system("clear");
		clear=0;

		for(int i=0;i<players; i++){
			syuugeki[i]=0;
		}
		for(int i=0;i<players; i++){
			die[i]=0;
		}
		syuugekikekka=0;

		wolfcount=0;
		uranaicount=0;
		foxcount=0;
		playerscount=0;

		for(int i=0; i<players; i++){
			if(player[i]>0){
				playerscount++;
			}
			if(player[i]==3){
				wolfcount++;
			}else if(player[i]==5){
				foxcount++;
			}
		}
		//勝利判定
		if(wolfcount==0){
			std::cout<<"この時点で人狼はいなくなりました\n";
			if(foxcount>0){
				std::cout<<"ですが、ここで妖狐が現れました\n";	  
				std::cout<<"妖狐陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}

				break;
			}else{
				std::cout<<"村人陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}

				break;
			}
		}
		if(wolfcount>=playerscount-wolfcount){
			std::cout<<"この時点で人狼の数が過半数を超えました\n";
			if(foxcount>0){
				std::cout<<"ですが、ここで妖狐が現れました\n";
				std::cout<<"妖狐陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}


				break;
			}else{
				std::cout<<"人狼陣営の勝ちです\n";
				for(int i=0; i<players; i++){
					if(job[i]==1){
						std::cout<<"プレイヤー"<<i+1<<"の役職は村人です\n";
					}else if(job[i]==2){
						std::cout<<"プレイヤー"<<i+1<<"の役職は占い師です\n";
					}else if(job[i]==3){
						std::cout<<"プレイヤー"<<i+1<<"の役職は人狼です\n";
					}else if(job[i]==4){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂人です\n";
					}else if(job[i]==5){
						std::cout<<"プレイヤー"<<i+1<<"の役職は妖狐です\n";
					}else if(job[i]==6){
						std::cout<<"プレイヤー"<<i+1<<"の役職は騎士です\n";
					}else if(job[i]==7){
						std::cout<<"プレイヤー"<<i+1<<"の役職は狂信者です\n";
					}

				}

				break;
			}
		}

	}
}
