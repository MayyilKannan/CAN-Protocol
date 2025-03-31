extern void delay_sec(int sec);
extern void delay_ms(int ms);
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
extern void uart_init(u32 baud);
extern void uart_tx(u8 data);
extern u8 uart_rx(void);
extern void uart_tx_string(char *ptr);
extern void adc_init(void);
extern int adc_read(u8 ch_num);
extern void config_vic(void);
extern void uart_Handler(void)__irq;
extern void en_uart_intr(void);



