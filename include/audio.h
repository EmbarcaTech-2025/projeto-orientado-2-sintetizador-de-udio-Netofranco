#ifndef AUDIO_H
#define AUDIO_H

#include <stdint.h>

#define SAMPLE_RATE_HZ 12000
#define RECORD_TIME_SEC 5
#define TOTAL_SAMPLES (SAMPLE_RATE_HZ * RECORD_TIME_SEC)

extern uint16_t audio_buffer[TOTAL_SAMPLES];

void init_adc();
void init_pwm_audio();
void grava_audio();
void reproduz_audio();
void mostra_waveform();
void test_pwm_tone(uint32_t freq);

#endif
