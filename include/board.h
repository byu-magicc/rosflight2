#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

// setup
void init_board(void);

// clock
uint32_t millis();
uint64_t micros();

// serial
void serial_write(uint8_t byte);
uint16_t serial_bytes_available(void);
uint8_t serial_read(void);

// sensors
void imu_register_callback(void (*callback)(void));
void imu_read_accel(float accel[3]);
void imu_read_gyro(float gyro[3]);
void imu_read_temperature(float *temperature);

bool mag_present(void);
void mag_read(float mag[3]);

bool baro_present(void);
void baro_read(float *pressure, float *temperature);

bool diff_pressure_present(void);
bool diff_pressure_read(float *diff_pressure, float *temperature);

bool sonar_present(void);
float sonar_read(void);

// RC
float rc_read(uint8_t channel); // return between -1 and 1 (or 0 and 1?)

// motors
void motor_write(uint8_t channel, float value); // send between 0 and 1

// non-volatile memory
void memory_init(void);
bool memory_read(void * dest, size_t len);
bool memory_write(const void * src, size_t len);

// LEDs
void led0_on(void);
void led0_off(void);
void led0_toggle(void);

void led1_on(void);
void led1_off(void);
void led1_toggle(void);
