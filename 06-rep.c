// 2610240070 daiju koyama


#include <stdio.h>
#include <stdlib.h>
#include <glsc3d_3.h>

#define L (80)  // 道路の長さ
#define RN (rand()/(double)RAND_MAX)  // 0.0～1.0の一様乱数を発生
#define TH (0.54)   // 自動車の密度（どれくらいの確率で配置するか）
#define TMAX (300)  // 時間繰り返しの回数

int main(){
    int i, t;
    int r1[L], r2[L];

    // 乱数の種を設定（毎回同じ乱数列が生成）
    srand(10);

    // 道路状況の初期化、自動車は TH の確率で置く
    for(i = 0; i < L; i++) {

        // 乱数がTH（配置確率、密度）より小さければ自動車配置
        if(RN < TH) {
            r1[i] = 1;
        // それ以外は、自動車なし
        } else {
            r1[i] = 0;
        }
        // 更新処理用の配列の初期化
        r2[i] = 0;
    }


    // GLSC3Dの初期化
    g_enable_highdpi();
    g_init("Traffic Jam", 1250, 200);
    // 自由座標系の定義
    g_def_scale_2D(1, 0.0, L, 0.0, 1.0, 25.0, 100.0, 1200.0, 30.0);
    g_sel_scale(1);
    g_cls();

    // 外枠の描画
    /*
    ここに for 文使って、g_box_2Dで格子をL個描く
    */
   	for (int c=0;c<L;c++){
		g_box_center_2D(0.5+c, 0.5, 1.0, 0.5, G_YES, G_NO);
	}


    // 現在の道路状況の表示
    // 車がなければ " "(空白)を表示、車があれば "o" を表示
    // 車があればg_marker_2Dで表示
    //（このコードには書いてないので自分で追加、必要に応じてマーカーの大きさや色を変更）

    for(i = 0; i < L ; i++) {
        if(r1[i] == 0) {
            printf(" ");
        } else {
            printf("o");
			g_marker_2D(0.5+i, 0.5);
			g_marker_size(5.0);
        }
    }
    printf("\n");

    // 画面への描画
    g_finish();
    // 一定時間停止
    g_sleep(1.0);

    // 時刻TMAXまで繰り返して、道路状況を更新
    for(t = 1; t < TMAX; t++) {

        // 自動車を右方向に移動、ただし円環状道路（端まで行ったら最初に戻る道路）を考える
        // もし一つ前に車があれば、移動できない（このコードには書いてないので、自分で追加）
		// if rule184, rewrite
        for(i = 0; i < L; i++) {
			if (r1[i] == 1){
				
				// center: 1
				if (r1[(i + 1) % L] == 1){
					// next: 1
					r2[i] = 1;
				}else{
					// next: 0
					r2[i] = 0;
				}

			}else{
				
				// center: 0
				if (r1[(L - 1 + i) % L] == 1){
					// before: 1
					r2[i] = 1;
				}else{
					//before: 0
					r2[i] = 0;
				}
			}
			// r2[(i + 1)%L] = r1[i];
        }

        // 道路状況の更新＆更新処理用の配列の初期化
        for(i = 0; i < L; i++) {
            r1[i] = r2[i];
            r2[i] = 0;
        }

        // 画面の消去
        g_cls();

        // 外枠の描画
        /*
        ここに for 文使って、g_box_2Dで格子をL個描く
        */
	   	for (int c=0;c<L;c++){
			g_box_center_2D(0.5+c, 0.5, 1.0, 0.5, G_YES, G_NO);
		}
	


        // 現在の道路状況の表示
        // 車がなければ " "(空白)を表示、車があれば "o" を表示
        // 車があればg_marker_2Dで表示
        //（このコードには書いてないので自分で追加、必要に応じてマーカーの大きさや色を変更）
    

        for(i = 0; i < L ; i++) {
            if(r1[i] == 0) {
                printf(" ");
            } else {
                printf("o");
				g_marker_2D(0.5+i, 0.5);
				g_marker_size(5.0);
            }
        }
        printf("\n");

        // 画面への描画
        g_finish();
        // 一定時間停止
        g_sleep(0.3);
    }

  
    return 0;
}
