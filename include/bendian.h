#if WORDS_BIGENDIAN

#ifdef __cplusplus
extern "C" {
#endif

void be2les(short* ip);
void be2leus(unsigned short* ip);
void be2lei(int* ip);
void be2leui(unsigned int* ip);
void be2lel(long* ip);
void be2leul(unsigned long* ip);
void be2lell(long long* lp);
void be2leull(unsigned long long* lp);

#ifdef __cplusplus
}
#endif

#endif
