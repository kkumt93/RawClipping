#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct RawInit {
	int  RAW_H_SIZE=0; /* 画像横サイズ */
	int  RAW_V_SIZE=0; /* 画像縦サイズ */
	int  CLIP_X_POINT=0; /* 切り抜き横座標 */
	int  CLIP_Y_POINT=0; /* 切り抜き縦座標 */
	int  CLIP_H_SIZE=0; /* 切り抜き横サイズ */
	int  CLIP_V_SIZE=0; /* 切り抜き縦サイズ */
};


void GetRawIni(char *filename, RawInit *raw_ini) {

	FILE *fp;

	/* ファイルのオープン */
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("%sのオープンに失敗しました.\n", filename);
		exit(EXIT_FAILURE);
	}

	char name[20] = {};
	int num=0;
	
	//ファイル設定値取得
	while (fscanf(fp, "%s %d", name, &num) != EOF) {

		if (strcmp(name, "RAW_H_SIZE") == 0) {
			raw_ini->RAW_H_SIZE = num;
		}
		else if (strcmp(name, "RAW_V_SIZE") == 0) {
			raw_ini->RAW_V_SIZE = num;
		}
		else if (strcmp(name, "CLIP_X_POINT") == 0) {
			raw_ini->CLIP_X_POINT = num;
		}
		else if (strcmp(name, "CLIP_Y_POINT") == 0) {
			raw_ini->CLIP_Y_POINT = num;
		}
		else if (strcmp(name, "CLIP_H_SIZE") == 0) {
			raw_ini->CLIP_H_SIZE = num;
		}
		else if (strcmp(name, "CLIP_V_SIZE") == 0) {
			raw_ini->CLIP_V_SIZE = num;
		}
		else {
			printf("%sは定義されていません\n", name);
			while (1);
		}

	}
	/* ファイルのクローズ */
    fclose(fp);

}
//デバッグ用
/*
printf("RAW_H_SIZE%d\n", raw_ini1.RAW_H_SIZE);
printf("RAW_V_SIZE%d\n", raw_ini1.RAW_V_SIZE);
printf("CLIP_X_POINT%d\n", raw_ini1.CLIP_X_POINT);
printf("CLIP_Y_POINT%d\n", raw_ini1.CLIP_Y_POINT);
printf("CLIP_H_SIZE%d\n", raw_ini1.CLIP_H_SIZE);
printf("CLIP_V_SIZE%d\n", raw_ini1.CLIP_V_SIZE);
*/



//argv[1] RawClipping.ini
//argv[2] file_list.txt
int main(int argc, char *argv[]) {

	RawInit raw_ini1;

	GetRawIni(argv[argc-1], &raw_ini1);

	while (1);

	return 0;
}