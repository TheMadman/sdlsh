add_executable(sdl-runner sdl-runner.c)

target_link_libraries(sdl-runner srvsh SDL3::SDL3)

install(TARGETS sdl-runner
	DESTINATION bin)
