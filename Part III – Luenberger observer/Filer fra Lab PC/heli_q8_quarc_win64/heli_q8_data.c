/*
 * heli_q8_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8".
 *
 * Model version              : 11.22
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Oct 22 15:54:26 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8.h"
#include "heli_q8_private.h"

/* Block parameters (default storage) */
P_heli_q8_T heli_q8_P = {
  /* Variable: A_lqr
   * Referenced by: '<S6>/Multiply'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.081565203835061231, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: B
   * Referenced by: '<S6>/Multiply1'
   */
  { 0.0, 0.0, 0.098165350075907723, 0.0, 0.0, 0.0, 0.52848484848484878, 0.0, 0.0,
    0.0 },

  /* Variable: C_lqr
   * Referenced by: '<S6>/Multiply3'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F
   * Referenced by: '<S8>/Constant1'
   */
  { 1.0, 1.0, 0.0, 0.0 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S5>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S5>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S8>/Constant'
   */
  { 3.4974113126365774E-15, 8.8110074360273369, 5.2756532275455956E-15,
    20.81692601886439, 7.5082479767392929, 1.1162722854835215E-16,
    -6.11999937474398E-16, -1.0, -0.99999999999999933, -3.5118598259087725E-16 },

  /* Variable: L
   * Referenced by: '<S6>/Multiply2'
   */
  { 2.0, 0.0, 0.0, 0.0, 0.081565203835061231, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S3>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: 0.001
   * Referenced by: '<S13>/Constant1'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S13>/Constant'
   */
  0.001,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 65
   * Referenced by: '<S4>/Constant1'
   */
  65.0,

  /* Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S4>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S4>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S4>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 2*pi/8192
   * Referenced by: '<S3>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S5>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S5>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S5>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S5>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S5>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S5>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 7.5
   * Referenced by: '<Root>/vs0'
   */
  7.5,

  /* Expression: -2*pi /4096
   * Referenced by: '<S3>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S3>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S3>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S3>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/K_ei'
   */
  0.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall1_SendBufferSize
   * Referenced by: '<S4>/Stream Call1'
   */
  8000,

  /* Computed Parameter: StreamCall1_ReceiveBufferSize
   * Referenced by: '<S4>/Stream Call1'
   */
  8000,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedWrite_MaxUnits
   * Referenced by: '<S4>/Stream Formatted Write'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S5>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall1_NonBlocking
   * Referenced by: '<S4>/Stream Call1'
   */
  1,

  /* Computed Parameter: StreamCall1_Active
   * Referenced by: '<S4>/Stream Call1'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S3>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S5>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S5>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S4>/String Constant'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 52U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S4>/Stream Call1'
   */
  0U,

  /* Computed Parameter: StreamCall1_Endian
   * Referenced by: '<S4>/Stream Call1'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S5>/Game Controller'
   */
  1U
};
