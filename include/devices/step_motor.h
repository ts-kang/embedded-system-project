#ifndef _STEP_MOTOR_H_
#define _STEP_MOTOR_H_

void step_motor_init(void);
void step_motor_destroy(void);
void step_motor_run(unsigned char motor_state);
void step_motor_stop(unsigned char motor_state);

#endif /* _STEP_MOTOR_H_ */
