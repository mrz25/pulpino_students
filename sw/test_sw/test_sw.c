#define __riscv__
//#define LED_DELAY 1000000

//#include <spi.h>
#include <gpio.h>
#include <uart.h>
//#include <utils.h>
#include <pulpino.h>
#include <kuz_driver.h>

int main()
{
  uart_set_cfg(0, 325); // 9600 baud UART, no parity (50MHz CPU)
  //CGREG |= (1 << CGKUZ);
  
  kuz_init();
  kuz_rstn();
  
  uint32_t * read_ptr;
  //uint32_t write_arr [4];
  char a[16];
  char uart_arr [16];
  int j;

  while(1){
    j = 0;
    for(int i = 15; i >= 0; i--){
      a[i] = uart_getchar();
    }
    kuz_write_data((uint32_t*) a);
    read_ptr = kuz_read_data();
    for (int i = 15; i > 0; i = i - 4)
    {
      uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
      uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
      uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
      uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
      j++;
    }
    uart_send(uart_arr, 16);
    uart_wait_tx_done();
  }
    //write_arr[j] = (a);
  //}
  
  //uint32_t write_arr [4];

  // write_arr[3] = 0x3ee5c99f;
  // write_arr[2] = 0x9a41c389;
  // write_arr[1] = 0xac17b4fe;
  // write_arr[0] = 0x99c72ae4;
  // set_gpio_pin_value(16, 1);

  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x79cfed3c;
  // write_arr[2] = 0x39fa7677;
  // write_arr[1] = 0xb970bb42;
  // write_arr[0] = 0xa5631ccd;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // //uart_clear();

  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x63a148b3;
  // write_arr[2] = 0xd9774ced;
  // write_arr[1] = 0xe1c54673;
  // write_arr[0] = 0xc68dcd03;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // //uart_clear();
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x2ed02c74;
  // write_arr[2] = 0x160391fd;
  // write_arr[1] = 0x9e8bd4ba;
  // write_arr[0] = 0x21e79a9d;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // set_gpio_pin_value(17, 1);


  // write_arr[3] = 0x74f24530;
  // write_arr[2] = 0x59092269;
  // write_arr[1] = 0x22ac9d24;
  // write_arr[0] = 0xb9ed3b20;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x03dde21c;
  // write_arr[2] = 0x095413db;
  // write_arr[1] = 0x093bb863;
  // write_arr[0] = 0x6d8fc082;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0xbdeb379c;
  // write_arr[2] = 0x9326a275;
  // write_arr[1] = 0xc58c7568;
  // write_arr[0] = 0x85c40d47;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x2dcabdf6;
  // write_arr[2] = 0xb6488f5f;
  // write_arr[1] = 0x3d56c2fd;
  // write_arr[0] = 0x3d2357b0;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x887adf8b;
  // write_arr[2] = 0x545c4334;
  // write_arr[1] = 0xe0070c63;
  // write_arr[0] = 0xd2f344a3;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);
  
  // write_arr[3] = 0x23feeb91;
  // write_arr[2] = 0x15fab3e4;
  // write_arr[1] = 0xf9739578;
  // write_arr[0] = 0x010f212c;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);

  // write_arr[3] = 0x53e0ebee;
  // write_arr[2] = 0x97b0c1b8;
  // write_arr[1] = 0x377ac5bc;
  // write_arr[0] = 0xe14cb4e8;
  // kuz_write_data(write_arr);
  // read_ptr = kuz_read_data();
  // j = 0;
  // for (int i = 15; i > 0; i = i - 4)
  // {
  //   uart_arr[i] = (char)((*( read_ptr + j ) << 24) >> 24);
  //   uart_arr[i-1] = (char)((*( read_ptr + j ) << 16) >> 24);
  //   uart_arr[i-2] = (char)((*( read_ptr + j ) << 8) >> 24);
  //   uart_arr[i-3] = (char)((*( read_ptr + j )) >> 24);
  //   j++;
  // }
  // uart_wait_tx_done();
  // uart_send(uart_arr, 16);


  // set_gpio_pin_value(17, 1);
/*set_pin_function(31, FUNC_GPIO);
  set_gpio_pin_direction(31, DIR_OUT);
  set_gpio_pin_value(31, 0);*/

  /*while(1) {
  
    for (int i = 0; i < LED_DELAY; i++) {
      //wait some time
      #ifdef __riscv__
          asm volatile ("nop");
      #else
          asm volatile ("l.nop");
      #endif
    }

    set_gpio_pin_value(31, 1);

    for (int i = 0; i < LED_DELAY; i++) {
      //wait some time
      #ifdef __riscv__
          asm volatile ("nop");
      #else
          asm volatile ("l.nop");
      #endif
    }

    set_gpio_pin_value(31, 0);
    
  }*/
  return 0;
}
