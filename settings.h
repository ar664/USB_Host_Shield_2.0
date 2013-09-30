/*
 * File:   settings.h
 * Author: AJK
 *
 * Created on September 23, 2013, 12:00 AM
 */

#ifndef USB_HOST_SHIELD_SETTINGS_H
#define	USB_HOST_SHIELD_SETTINGS_H
#include "macros.h"

////////////////////////////////////////////////////////////////////////////////
// DEBUGGING
////////////////////////////////////////////////////////////////////////////////

/* Set this to 1 to activate serial debugging */
#define ENABLE_UHS_DEBUGGING 0

/* This can be used to select which serial port to use if multiple are available */
#ifndef USB_HOST_SERIAL
#define USB_HOST_SERIAL Serial
#endif

////////////////////////////////////////////////////////////////////////////////
// Manual boards activation
////////////////////////////////////////////////////////////////////////////////

/* Set this to 1 if you are using an Arduino Mega ADK board with MAX3421e built-in */
#define USE_UHS_MEGA_ADK 0

/* Set this to 1 if you are using a Teensy 1.0 or 2.0 */
#define USE_UHS_TEENSY 0

/* Set this to 1 if you are using a Sanguino */
#define USE_UHS_SANGUINO 0

/* Set this to 1 if you are using a Black Widdow */
#define USE_UHS_BLACK_WIDDOW 0

////////////////////////////////////////////////////////////////////////////////
// MASS STORAGE
////////////////////////////////////////////////////////////////////////////////
// <<<<<<<<<<<<<<<< IMPORTANT >>>>>>>>>>>>>>>
// Set this to 1 to support single LUN devices, and save RAM. -- I.E. thumb drives.
// Each LUN needs ~13 bytes to be able to track the state of each unit.
#ifndef MASS_MAX_SUPPORTED_LUN
#define MASS_MAX_SUPPORTED_LUN 8
#endif

////////////////////////////////////////////////////////////////////////////////
// AUTOMATIC Settings
////////////////////////////////////////////////////////////////////////////////

#if !defined(DEBUG_USB_HOST) && ENABLE_UHS_DEBUGGING
#define DEBUG_USB_HOST
#endif

#if !defined(BOARD_TEENSY_PLUS_PLUS) && (defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__))
#define BOARD_TEENSY_PLUS_PLUS
#endif

// No user serviceable parts below this line, DO NOT change anything below here
// When will we drop support for the older bug-ridden stuff?
#if defined(ARDUINO) && ARDUINO >=100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif
#include <avr/pgmspace.h>

#endif	/* SETTINGS_H */