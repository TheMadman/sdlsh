#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <srvsh.h>

#define DEFAULT_HEIGHT 720
#define DEFAULT_WIDTH 1280

SDL_Window *window;
SDL_Renderer *renderer;

ssize_t write_event(int fd, SDL_Event *event)
{
	return writeop(
		fd,
		event->type,
		event,
		sizeof(*event)
	);
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
		return SDL_APP_FAILURE;

	if (
		!SDL_CreateWindowAndRenderer(
			"some-string",
			DEFAULT_WIDTH,
			DEFAULT_HEIGHT,
			0,
			&window,
			&renderer
		)
	)
		return SDL_APP_FAILURE;

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	for (int i = CLI_BEGIN; i < cli_end(); i++) {
		write_event(i, event);
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
