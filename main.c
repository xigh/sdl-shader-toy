#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

extern GLboolean glInit();
extern void glDraw(int windowW, int windowH, int cursorX, int cursorY);

int main()
{
    SDL_Window *win;
    SDL_GLContext ctx;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    int windowS = 60;
    int windowW = windowS * 16;
    int windowH = windowS * 9;
    int windowF = SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN;
    int cursorX = 100;
    int cursorY = 100;

    win = SDL_CreateWindow("SDL OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                           windowW, windowH, windowF);
    if (win == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    ctx = SDL_GL_CreateContext(win);

    if (!glInit())
        return EXIT_FAILURE;

    // SDL_ShowCursor(SDL_DISABLE);

    SDL_bool close = SDL_FALSE;
    while (!close)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                close = SDL_TRUE;
                break;

            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_SHOWN:
                    SDL_Log("event: windoweventshown\n");
                    break;

                case SDL_WINDOWEVENT_HIDDEN:
                    SDL_Log("event: windoweventhidden");
                    break;

                case SDL_WINDOWEVENT_EXPOSED:
                    SDL_Log("event: windoweventexposed");
                    break;

                case SDL_WINDOWEVENT_MOVED:
                    SDL_Log("event: windoweventmoved: %dx%d", event.window.data1, event.window.data2);
                    break;

                case SDL_WINDOWEVENT_RESIZED:
                    windowW = event.window.data1;
                    windowH = event.window.data2;
                    SDL_Log("event: windoweventresized %dx%d", windowW, windowH);
                    break;

                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    SDL_Log("event: windoweventsizechanged");
                    break;

                case SDL_WINDOWEVENT_MINIMIZED:
                    SDL_Log("event: windoweventminimized");
                    break;

                case SDL_WINDOWEVENT_MAXIMIZED:
                    SDL_Log("event: windoweventmaximized");
                    break;

                case SDL_WINDOWEVENT_RESTORED:
                    SDL_Log("event: windoweventrestored");
                    break;

                case SDL_WINDOWEVENT_ENTER:
                    SDL_Log("event: windowevententer");
                    break;

                case SDL_WINDOWEVENT_LEAVE:
                    SDL_Log("event: windoweventleave");
                    break;

                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    SDL_Log("event: windoweventfocusgained");
                    break;

                case SDL_WINDOWEVENT_FOCUS_LOST:
                    SDL_Log("event: windoweventfocuslost");
                    break;

                case SDL_WINDOWEVENT_CLOSE:
                    SDL_Log("event: windoweventclose");
                    break;

                case SDL_WINDOWEVENT_TAKE_FOCUS:
                    break;

                case SDL_WINDOWEVENT_HIT_TEST:
                    SDL_Log("event: windoweventtakefocus");
                    SDL_Log("event: windoweventhittest");
                    break;

                default:
                    SDL_Log("event: windowevent: %04x", event.window.event);
                    break;
                }
                break;

            case SDL_AUDIODEVICEADDED:
            case SDL_AUDIODEVICEREMOVED:
                break;

            case SDL_JOYAXISMOTION:
            case SDL_JOYBALLMOTION:
            case SDL_JOYHATMOTION:
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
            case SDL_JOYDEVICEADDED:
            case SDL_JOYDEVICEREMOVED:

            case SDL_CONTROLLERAXISMOTION:
            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
            case SDL_CONTROLLERDEVICEADDED:
            case SDL_CONTROLLERDEVICEREMOVED:
            case SDL_CONTROLLERDEVICEREMAPPED:
            case SDL_KEYUP:
            case SDL_TEXTEDITING:
            case SDL_TEXTINPUT:
            case SDL_KEYMAPCHANGED:
                break;

            case SDL_MOUSEMOTION:
                cursorX = event.motion.x;
                cursorY = event.motion.y;
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:

            case SDL_MOUSEWHEEL:
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                default:
                    break;

                case SDL_SCANCODE_ESCAPE:
                    close = SDL_TRUE;
                    break;

                case SDL_SCANCODE_F:
                    windowF = windowF ^ SDL_WINDOW_FULLSCREEN_DESKTOP;
                    SDL_SetWindowFullscreen(win, windowF);
                }
                break;

            default:
                break;
            }
        }

        glDraw(windowW, windowH, cursorX, cursorY);
        SDL_GL_SwapWindow(win);
    }

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
