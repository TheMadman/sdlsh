add_custom_target(
	protocol.h.i
	"${CMAKE_C_COMPILER}" -E "${CMAKE_CURRENT_SOURCE_DIR}/protocol.h" -I"${SDL_Headers}" > protocol.h.i
	BYPRODUCTS protocol.h.i)

add_custom_target(
	sdl-opcodes.db
	"${CMAKE_CURRENT_SOURCE_DIR}/opcode-generator" < protocol.h.i > sdl-opcodes.db
	BYPRODUCTS sdl-opcodes.db)
add_custom_target(
	sdlsh-adapter.h
	"${CMAKE_CURRENT_SOURCE_DIR}/adapter-generator" < protocol.h.i > sdlsh-adapter.h
	BYPRODUCTS sdhsl-adapter.h)

add_dependencies(sdl-opcodes.db protocol.h.i)
add_dependencies(sdlsh-adapter.h protocol.h.i)

install(FILES sdl-opcodes.db
	DESTINATION share)
install(FILES sdlsh-adapter.h
	DESTINATION include)
