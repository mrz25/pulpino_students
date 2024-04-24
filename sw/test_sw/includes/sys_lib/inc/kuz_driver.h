#ifndef _KUZ_DRIVER_H_
#define _KUZ_DRIVER_H_


#include <pulpino.h>
#include <stdint.h>

#define KUZ_REG_RST                       ( KUZ_BASE_ADDR + 0x00 )
#define KUZ_REG_REQ                       ( KUZ_BASE_ADDR + 0x04 )
#define KUZ_REG_ACK                       ( KUZ_BASE_ADDR + 0x08 )
#define KUZ_REG_VALID                     ( KUZ_BASE_ADDR + 0x0C )
#define KUZ_REG_BUSY                      ( KUZ_BASE_ADDR + 0x10 )
#define KUZ_REG_DATA_IN_0                 ( KUZ_BASE_ADDR + 0x14 )
#define KUZ_REG_DATA_IN_1                 ( KUZ_BASE_ADDR + 0x18 )
#define KUZ_REG_DATA_IN_2                 ( KUZ_BASE_ADDR + 0x1c )
#define KUZ_REG_DATA_IN_3                 ( KUZ_BASE_ADDR + 0x20 )
#define KUZ_REG_DATA_OUT_0                ( KUZ_BASE_ADDR + 0x24 )
#define KUZ_REG_DATA_OUT_1                ( KUZ_BASE_ADDR + 0x28 )
#define KUZ_REG_DATA_OUT_2                ( KUZ_BASE_ADDR + 0x2c )
#define KUZ_REG_DATA_OUT_3                ( KUZ_BASE_ADDR + 0x30 )

#define KUZ_RST                        REG( KUZ_REG_RST          )
#define KUZ_REQ                        REG( KUZ_REG_REQ          )
#define KUZ_ACK                        REG( KUZ_REG_ACK          )
#define KUZ_VALID                      REG( KUZ_REG_VALID        )
#define KUZ_BUSY                       REG( KUZ_REG_BUSY         )
#define KUZ_DATA_IN_0                  REG( KUZ_REG_DATA_IN_0    )
#define KUZ_DATA_IN_1                  REG( KUZ_REG_DATA_IN_1    )
#define KUZ_DATA_IN_2                  REG( KUZ_REG_DATA_IN_2    )
#define KUZ_DATA_IN_3                  REG( KUZ_REG_DATA_IN_3    )
#define KUZ_DATA_OUT_0                 REG( KUZ_REG_DATA_OUT_0   )
#define KUZ_DATA_OUT_1                 REG( KUZ_REG_DATA_OUT_1   )
#define KUZ_DATA_OUT_2                 REG( KUZ_REG_DATA_OUT_2   )
#define KUZ_DATA_OUT_3                 REG( KUZ_REG_DATA_OUT_3   )
// __attribute__ ((packed)) struct KUZ_APB{
// 	uint32_t KUZ_RST;
// 	uint32_t KUZ_REQ;
// 	uint32_t KUZ_ACK;
// 	uint32_t KUZ_VALID;
// 	uint32_t KUZ_BUSY;
// 	uint32_t KUZ_DATA_IN_0;
// 	uint32_t KUZ_DATA_IN_1;
// 	uint32_t KUZ_DATA_IN_2;
// 	uint32_t KUZ_DATA_IN_3;
// 	uint32_t KUZ_DATA_OUT_0;
// 	uint32_t KUZ_DATA_OUT_1;
// 	uint32_t KUZ_DATA_OUT_2;
// 	uint32_t KUZ_DATA_OUT_3;
// };


void kuz_init(void);
void kuz_rstn(void);
void kuz_write_data(uint32_t *data);
uint32_t * kuz_read_data(void);
//int kuz_read_status(void);
/*int kuz_read_idle_status(void);
int kuz_read_key_phase_status(void);
int kuz_read_s_phase_status(void);
int kuz_read_l_phase_status(void);
int kuz_read_finish_status(void);*/

#endif //