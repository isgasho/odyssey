#ifndef MM_CHANNEL_H
#define MM_CHANNEL_H

/*
 * machinarium.
 *
 * cooperative multitasking engine.
*/

typedef struct mm_channelrd mm_channelrd_t;
typedef struct mm_channel   mm_channel_t;

struct mm_channelrd
{
	mm_call_t call;
	int       signaled;
	mm_list_t link;
};

struct mm_channel
{
	mm_list_t incoming;
	int       incoming_count;
	mm_list_t readers;
	int       readers_count;
};

void mm_channel_init(mm_channel_t*);
void mm_channel_free(mm_channel_t*);
void mm_channel_write(mm_channel_t*, mm_msg_t*);
mm_msg_t*
mm_channel_read(mm_channel_t*, int);

#endif /* MM_CHANNEL_H */
