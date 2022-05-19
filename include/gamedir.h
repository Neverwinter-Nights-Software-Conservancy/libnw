#ifdef __cplusplus
extern "C" {
#endif

/**
 * extracts the pathname of the game's root directory (from the environment
 * in Unix-like systems) and returns it if found.  Otherwise, returns 0.
 */
extern char* get_game_dir(void);

#ifdef __cplusplus
}
#endif
