#include <stdio.h>

#define WIDTH 3
#define HEIGHT 5

typedef enum {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,
}SCENE;

typedef struct {
	int Board[HEIGHT][WIDTH];
	SCENE Scene;
} Status;

Status g_Status;

void PrintScneName() {
	const char* sceneName;

	switch ( g_Status.Scene) {
	case SCENE_TITLE:
		sceneName = "TITLE";
		break;
	case SCENE_GAME:
		sceneName = "GAME";
		break;
	case SCENE_RESULT:
		sceneName = "RESULT";
		break;
	default:
		sceneName = "Unknown scene name!";
		break;
	}

	printf("Current scene: %s\n\n", sceneName);
}

void SetScene(SCENE scene) {
	g_Status.Scene = scene;
	PrintScneName();
}

void InitBoard() {
	printf("Board status:\n");
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			int value = 2;
			g_Status.Board[row][col] = value;
			printf("%d", value);
		}

		printf("\n");
	}
}

int main() {
	SetScene(SCENE_TITLE);

	SetScene(SCENE_GAME);

	InitBoard();

	printf("\n");

	PrintScneName();

	while (true);
}
