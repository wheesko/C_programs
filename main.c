#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include <time.h>
void sendinti(stackStruct *gautasStekas);
void gaminti(int kiekis, stackStruct *gautasStekas);
void ismesti(stackStruct *gautasStekas,int spoiled, int *profit, int price);
int noriSumustinio(int tikimybe);
void printStack(stackStruct *stackIn);
void laikytuvai2(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina);
void laikytuvai3(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina);
void laikytuvai4(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina);
int main(){
	int tikimybe = 0;
	int kiekis = 0;
	int periodiskumas = 0;
	int sugedo = 0;
	int darboDiena = 0;
	int kaina = 0;
	int laikytuvuKiekis = 0;
	int r = 0;
	srand((unsigned)time(NULL));
	printf("Iveskite tikimybe procentais, kad klientas uzsimanys sumustinio:\n");
	scanf("%d", &tikimybe);
	printf("Iveskite kieki pagamintu sumustiniu:\n");
	scanf("%d", &kiekis);
	printf("Iveskite kas kiek min gaminami sumustiniai:\n");
	scanf("%d", &periodiskumas);
	printf("Iveskite po kiek laiko min ismetamas sumustinis:\n");
	scanf("%d", &sugedo);
	printf("Iveskite sumustinio kaina:\n");
	scanf("%d", &kaina);
	printf("Iveskite darbo dienos ilgi valandomis:\n");
	scanf("%d", &darboDiena);
//	printf("Iveskite kiek laikytuvu tures kavine (2,3 arba 4)\n");
//	scanf("%d", &laikytuvuKiekis);

	//if(laikytuvuKiekis == 2){
		laikytuvai2(tikimybe, kiekis, periodiskumas, sugedo, darboDiena, kaina);
	//}
	//else if(laikytuvuKiekis == 3){
		laikytuvai3(tikimybe, kiekis, periodiskumas, sugedo, darboDiena, kaina);
	//}
	//else if(laikytuvuKiekis == 4){
		laikytuvai4(tikimybe, kiekis, periodiskumas, sugedo, darboDiena, kaina);
	//}
}
void gaminti(int kiekis, stackStruct *gautasStekas){
	int k = 0;
	for(int i = 0; i < kiekis; i++){
		Push(gautasStekas, k);
	}
}
void sendinti(stackStruct *gautasStekas){
	for(int i = 0; i < gautasStekas -> elementCount; i++){
		(gautasStekas -> contents[i])++;
	}
}
void ismesti(stackStruct *gautasStekas,int spoiled, int *profit, int price){
	int ismesta = 0;
	for(int i = gautasStekas -> elementCount - 1 ; i >= 0; i--){
		//printf("%d\n", gautasStekas -> Scontents[i]);
		if(gautasStekas -> contents[i] > spoiled){
			//gautasStekas -> contents[i] = 0;
			*profit-=price;
			for(int o = i + 1; o < gautasStekas -> elementCount - 1; o++){
				gautasStekas -> contents[o-1] = gautasStekas -> contents[o];
			}
			(gautasStekas -> elementCount)--;
			ismesta++;
		}
	}
//printf("ismete %d\n", ismesta);
}
int noriSumustinio(int tikimybe){
	//printf("%d\n", tikimybe);
	int r = (rand() % 100) < tikimybe;
	//printf("%d\n", r);
	//if( tikimybe >= r) {/*printf("%d >= %d\n ", tikimybe, r);*/ return 1;}
	//else { return 0;}
	return r;
}
void printStack(stackStruct *stackIn){
	for(int i = 0; i < stackIn -> elementCount; i++)printf("%d\n", stackIn -> contents[i]);

}
void laikytuvai2(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina){
	stackStruct laikytuvas;
	stackStruct laikytuvas1;
	int pelnas = 0;
	int pardave = 0;
	int pagamino = 0;
	int r = 0;
	printf("/////////////////////////////////////////////\n");
	printf("SKAICIUOJAME PELNA, KAI TURIME 2 STEKUS\n");
	Create(&laikytuvas);
	//printf("cia1");
	Create(&laikytuvas1);
	//printf("cia");
	for(int o = 0; o < 3; o++){
		for(int i = 0; i <= darboDiena * 60 ; i++){
			if (i % (periodiskumas) == 0){
				if((laikytuvas.elementCount) <= (laikytuvas1.elementCount)){
					gaminti(kiekis, &laikytuvas);
					//pelnas-=kaina;
					pagamino+=kiekis;
				}
				else{
					gaminti(kiekis, &laikytuvas1);
					//pelnas-=kaina;
					pagamino+=kiekis;
				}
			}

			if (noriSumustinio(tikimybe) == 1){

					r = rand() % 2 + 1;
					//printf("sugeneruotas 1 ar 2: %d\n", r);
					if((r == 1) && (IsEmpty(&laikytuvas)!=1)){
						Pop(&laikytuvas);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 2) && (IsEmpty(&laikytuvas1)!=1)){
						Pop(&laikytuvas1);
						pelnas+= kaina;
						pardave++;

					}

			}
			if(IsEmpty(&laikytuvas)!=1)sendinti(&laikytuvas);
			if(IsEmpty(&laikytuvas1)!=1)sendinti(&laikytuvas1);
		}
		//printStack(&laikytuvas, 0);
		//printStack(&laikytuvas1, 0);
		//printf("pardave: %d\n", pardave);
	//	printf("pagamino: %d\n", pagamino);

		if(IsEmpty(&laikytuvas)!=1)ismesti(&laikytuvas,sugedo,&pelnas,kaina);
		if(IsEmpty(&laikytuvas1)!=1)ismesti(&laikytuvas1,sugedo,&pelnas,kaina);
		//printf("sumustiniu 1 laikytuve: %d\n", laikytuvas.elementCount);
		//printf("sumustiniu 2 laikytuve: %d\n", laikytuvas1.elementCount);

	}
	//printStack(&laikytuvas, 1);
	Destroy(&laikytuvas);
	Destroy(&laikytuvas1);
	printf("pelnas: %d\n", pelnas);
	printf("pardave: %d\n", pardave);
	printf("pagamino: %d\n", pagamino);
}
/*void laikytuvai3(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina){
	stackStruct laikytuvas;
	stackStruct laikytuvas1;
	stackStruct laikytuvas2;
	int pelnas = 0;
	int pardave = 0;
	int pagamino = 0;
	int r = 0;
	printf("/////////////////////////////////////////////\n");
	printf("SKAICIUOJAME PELNA, KAI TURIME 3 LAIKYTUVUS\n");
	Create(&laikytuvas);
	Create(&laikytuvas1);
	Create(&laikytuvas2);
	for(int o = 0; o < 3; o++){
		for(int i = 0; i <= darboDiena * 60; i++){
			if (i % (periodiskumas) == 0){
				if((laikytuvas.elementCount <= laikytuvas1.elementCount) && (laikytuvas.elementCount <= laikytuvas2.elementCount)){
					gaminti(kiekis, &laikytuvas);
					pagamino+=kiekis;
				}
				else if((laikytuvas1.elementCount<= laikytuvas2.elementCount) && (laikytuvas1.elementCount <= laikytuvas.elementCount)){
					gaminti(kiekis, &laikytuvas1);
					pagamino+=kiekis;
				}
				else{
					gaminti(kiekis, &laikytuvas2);
					pagamino+=kiekis;
				}
			}

			if (noriSumustinio(tikimybe) == 1){
				if ((IsEmpty(&laikytuvas) != 1) && (IsEmpty(&laikytuvas1) != 1)){
					int r = rand() % 3 + 1;
					if((r == 1) && (IsEmpty(&laikytuvas) != 1)){
						Pop(&laikytuvas);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 2) && (IsEmpty(&laikytuvas1) != 1)){
						Pop(&laikytuvas1);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 3) && (IsEmpty(&laikytuvas2) != 1)){
                        Pop(&laikytuvas2);
						pelnas+= kaina;
						pardave++;
					}
				}
			}
			if(IsEmpty(&laikytuvas)!=1)sendinti(&laikytuvas);
			if(IsEmpty(&laikytuvas1)!=1)sendinti(&laikytuvas1);
			if(IsEmpty(&laikytuvas2)!=1)sendinti(&laikytuvas2);
		}
		if(IsEmpty(&laikytuvas)!=1)ismesti(&laikytuvas,sugedo,&pelnas,kaina);
		if(IsEmpty(&laikytuvas1)!=1)ismesti(&laikytuvas1,sugedo,&pelnas,kaina);
		if(IsEmpty(&laikytuvas2)!=1)ismesti(&laikytuvas2,sugedo,&pelnas,kaina);
		}

	Destroy(&laikytuvas);
	Destroy(&laikytuvas1);
	Destroy(&laikytuvas2);
	printf("pelnas: %d\n", pelnas);
	printf("pardave: %d\n", pardave);
	printf("pagamino: %d\n", pagamino);

}*/
/*void laikytuvai4(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina){
	stackStruct laikytuvas;
	stackStruct laikytuvas1;
	stackStruct laikytuvas2;
	stackStruct laikytuvas3;
	int pelnas = 0;
	int pardave = 0;
	int pagamino = 0;
	int r = 0;
	printf("/////////////////////////////////////////////\n");
	printf("SKAICIUOJAME PELNA, KAI TURIME 4 LAIKYTUVUS\n");
	Create(&laikytuvas);
	Create(&laikytuvas1);
	Create(&laikytuvas2);
	Create(&laikytuvas3);
	for(int o = 0; o < 3; o++){
		for(int i = 0; i <= darboDiena * 60; i++){
			if (i % (periodiskumas ) == 0){
				if((laikytuvas.elementCount <= laikytuvas1.elementCount) && (laikytuvas.elementCount <= laikytuvas2.elementCount) && (laikytuvas.elementCount <= laikytuvas3.elementCount)){
					gaminti(kiekis, &laikytuvas);
					pagamino+=kiekis;
				}
				else if((laikytuvas1.elementCount<= laikytuvas2.elementCount) && (laikytuvas1.elementCount <= laikytuvas.elementCount)&& (laikytuvas1.elementCount <= laikytuvas3.elementCount))				{
					gaminti(kiekis, &laikytuvas1);
					pagamino+=kiekis;
				}
				else if((laikytuvas2.elementCount<= laikytuvas1.elementCount) && (laikytuvas2.elementCount <= laikytuvas.elementCount)&& (laikytuvas2.elementCount <= laikytuvas3.elementCount))	{
					gaminti(kiekis, &laikytuvas2);
					pagamino+=kiekis;
				}
				else{
					gaminti(kiekis, &laikytuvas3);
					pagamino+=kiekis;
				}
			}

			if (noriSumustinio(tikimybe) == 1){
				if ((IsEmpty(&laikytuvas) != 1) && (IsEmpty(&laikytuvas1) != 1)){
					int r = rand() % 4 + 1;
					if((r == 1) && (IsEmpty(&laikytuvas) != 1)){
						Pop(&laikytuvas);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 2) && (IsEmpty(&laikytuvas1) != 1)){
						Pop(&laikytuvas1);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 3) && (IsEmpty(&laikytuvas2) != 1)){
						Pop(&laikytuvas2);
						pelnas+= kaina;
						pardave++;
					}
					if((r == 4) && (IsEmpty(&laikytuvas3) != 1)){
						Pop(&laikytuvas3);
						pelnas+= kaina;
						pardave++;
					}
				}
			}
				if(!IsEmpty(&laikytuvas))sendinti(&laikytuvas);
				if(!IsEmpty(&laikytuvas1))sendinti(&laikytuvas1);
				if(!IsEmpty(&laikytuvas2))sendinti(&laikytuvas2);
				if(!IsEmpty(&laikytuvas3))sendinti(&laikytuvas3);
		}
			if(!IsEmpty(&laikytuvas))ismesti(&laikytuvas,sugedo,&pelnas,kaina);
			if(!IsEmpty(&laikytuvas1))ismesti(&laikytuvas1,sugedo,&pelnas,kaina);
			if(!IsEmpty(&laikytuvas2))ismesti(&laikytuvas2,sugedo,&pelnas,kaina);
			if(!IsEmpty(&laikytuvas3))ismesti(&laikytuvas3,sugedo,&pelnas,kaina);
		}
	Destroy(&laikytuvas);
	Destroy(&laikytuvas1);
	Destroy(&laikytuvas2);
	Destroy(&laikytuvas3);
	printf("pelnas: %d\n", pelnas);
	printf("pardave: %d\n", pardave);
	printf("pagamino: %d\n", pagamino);
}*/
void laikytuvai3(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina){
    stackStruct laikytuvas;
    stackStruct laikytuvas1;
    int pelnas = 0;
    int pardave = 0;
    int pagamino = 0;
    int r = 0;
    printf("/////////////////////////////////////////////\n");
    printf("SKAICIUOJAME PELNA, KAI TURIME 1 STEKA 1 EILE\n");
    Create(&laikytuvas);
    //printf("cia1");
    Create(&laikytuvas1);
    //printf("cia");
    for(int o = 0; o < 3; o++){
        for(int i = 0; i <= darboDiena * 60 ; i++){
            if (i % (periodiskumas) == 0){
                if((laikytuvas.elementCount) <= (laikytuvas1.elementCount)){
                    gaminti(kiekis, &laikytuvas);
                    //pelnas-=kaina;
                    pagamino+=kiekis;
                }
                else{
                    gaminti(kiekis, &laikytuvas1);
                    //pelnas-=kaina;
                    pagamino+=kiekis;
                }
            }

            if (noriSumustinio(tikimybe) == 1){

                r = rand() % 2 + 1;
                //printf("sugeneruotas 1 ar 2: %d\n", r);
                if((r == 1) && (IsEmpty(&laikytuvas)!=1)){
                    Pop(&laikytuvas);
                    pelnas+= kaina;
                    pardave++;
                }
                if((r == 2) && (IsEmpty(&laikytuvas1)!=1)){
                    PopLast(&laikytuvas1);
                    pelnas+= kaina;
                    pardave++;

                }

            }
            if(IsEmpty(&laikytuvas)!=1)sendinti(&laikytuvas);
            if(IsEmpty(&laikytuvas1)!=1)sendinti(&laikytuvas1);
        }
        //printStack(&laikytuvas, 0);
        //printStack(&laikytuvas1, 0);
        //printf("pardave: %d\n", pardave);
        //	printf("pagamino: %d\n", pagamino);

        if(IsEmpty(&laikytuvas)!=1)ismesti(&laikytuvas,sugedo,&pelnas,kaina);
        if(IsEmpty(&laikytuvas1)!=1)ismesti(&laikytuvas1,sugedo,&pelnas,kaina);
        //printf("sumustiniu 1 laikytuve: %d\n", laikytuvas.elementCount);
        //printf("sumustiniu 2 laikytuve: %d\n", laikytuvas1.elementCount);

    }
    //printStack(&laikytuvas, 1);
    Destroy(&laikytuvas);
    Destroy(&laikytuvas1);
    printf("pelnas: %d\n", pelnas);
    printf("pardave: %d\n", pardave);
    printf("pagamino: %d\n", pagamino);
}
void laikytuvai4(int tikimybe, int kiekis, int periodiskumas, int sugedo, int darboDiena, int kaina){
    stackStruct laikytuvas;
    stackStruct laikytuvas1;
    int pelnas = 0;
    int pardave = 0;
    int pagamino = 0;
    int r = 0;
    printf("/////////////////////////////////////////////\n");
    printf("SKAICIUOJAME PELNA, KAI TURIME 2 EILES\n");
    Create(&laikytuvas);
    //printf("cia1");
    Create(&laikytuvas1);
    //printf("cia");
    for(int o = 0; o < 3; o++){
        for(int i = 0; i <= darboDiena * 60 ; i++){
            if (i % (periodiskumas) == 0){
                if((laikytuvas.elementCount) <= (laikytuvas1.elementCount)){
                    gaminti(kiekis, &laikytuvas);
                    //pelnas-=kaina;
                    pagamino+=kiekis;
                }
                else{
                    gaminti(kiekis, &laikytuvas1);
                    //pelnas-=kaina;
                    pagamino+=kiekis;
                }
            }

            if (noriSumustinio(tikimybe) == 1){

                r = rand() % 2 + 1;
                //printf("sugeneruotas 1 ar 2: %d\n", r);
                if((r == 1) && (IsEmpty(&laikytuvas)!=1)){
                    PopLast(&laikytuvas);
                    pelnas+= kaina;
                    pardave++;
                }
                if((r == 2) && (IsEmpty(&laikytuvas1)!=1)){
                    PopLast(&laikytuvas1);
                    pelnas+= kaina;
                    pardave++;

                }

            }
            if(IsEmpty(&laikytuvas)!=1)sendinti(&laikytuvas);
            if(IsEmpty(&laikytuvas1)!=1)sendinti(&laikytuvas1);
        }
        //printStack(&laikytuvas, 0);
        //printStack(&laikytuvas1, 0);
        //printf("pardave: %d\n", pardave);
        //	printf("pagamino: %d\n", pagamino);

        if(IsEmpty(&laikytuvas)!=1)ismesti(&laikytuvas,sugedo,&pelnas,kaina);
        if(IsEmpty(&laikytuvas1)!=1)ismesti(&laikytuvas1,sugedo,&pelnas,kaina);
        //printf("sumustiniu 1 laikytuve: %d\n", laikytuvas.elementCount);
        //printf("sumustiniu 2 laikytuve: %d\n", laikytuvas1.elementCount);

    }
    //printStack(&laikytuvas, 1);
    Destroy(&laikytuvas);
    Destroy(&laikytuvas1);
    printf("pelnas: %d\n", pelnas);
    printf("pardave: %d\n", pardave);
    printf("pagamino: %d\n", pagamino);
}