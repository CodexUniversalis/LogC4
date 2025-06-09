/**
  * @file timezones.h
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The header file that contains the timezone enum for the @a Logc4
  * library. The information for them has been taken from
  * <a href="https://www.timeanddate.com/time/zones/">timeanddate.com</a>.
  * @version 0.1.0
  * @date 2025-06-08: Created.
  * GitHub <a href="@ghc/">commit</a>. @n @n
  * Changelog
  * @copyright Copyright (c) 2025
*/
#pragma once
#ifndef TIMEZONES_H
#define TIMEZONES_H

/**
  * The length of the timezone array @a TZS.
*/
#define TZS_LEN 381
/**
  * The max length of an array of locations associated with a timezone.
*/
#define LOCATIONS_ARR_LEN 4
/**
  * The max length of a location string.
*/
#define LOCATIONS_STR_LEN 15

/**
  * @brief An enum of the acceptable timezones.
  *
  * These values are taken from
  * <a href="https://www.timeanddate.com/time/zones/">timeanddate.com</a>. See
  * this for all additional information.
*/
typedef enum{
    /**
      * The local timezone.
    */
    LOGC4_TZ_LOCAL = -1,
    /**
      * The timezone for <i>Coordinated Universal Time</i>.
    */
    LOGC4_TZ_UTC,
    /**
      * The timezone for <i>Alfa Time Zone</i>.
    */
    LOGC4_TZ_A,
    /**
      * The timezone for <i>Australian Central Daylight Time</i>.
    */
    LOGC4_TZ_ACDT,
    /**
      * The timezone for <i>Australian Central Standard Time</i>.
    */
    LOGC4_TZ_ACST,
    /**
      * The timezone for <i>Acre Time</i>.
    */
    LOGC4_TZ_ACT1,
    /**
      * The timezone for <i>Australian Central Time</i>.
    */
    LOGC4_TZ_ACT2,
    /**
      * The timezone for <i>Australian Central Western Standard Time</i>.
    */
    LOGC4_TZ_ACWST,
    /**
      * The timezone for <i>Atlantic Daylight Saving Time</i>.
    */
    LOGC4_TZ_ADST1,
    /**
      * The timezone for <i>Alaska Daylight Saving Time</i>.
    */
    LOGC4_TZ_ADST2,
    /**
      * The timezone for <i>Arabia Daylight Time</i>.
    */
    LOGC4_TZ_ADT1,
    /**
      * The timezone for <i>Atlantic Daylight Time</i>.
    */
    LOGC4_TZ_ADT2,
    /**
      * The timezone for <i>Australian Eastern Daylight Time</i>.
    */
    LOGC4_TZ_AEDT,
    /**
      * The timezone for <i>Australian Eastern Standard Time</i>.
    */
    LOGC4_TZ_AEST,
    /**
      * The timezone for <i>Australian Eastern Time</i>.
    */
    LOGC4_TZ_AET1,
    /**
      * The timezone for <i>Australian Eastern Time</i>.
    */
    LOGC4_TZ_AET2,
    /**
      * The timezone for <i>Afghanistan Time</i>.
    */
    LOGC4_TZ_AFT,
    /**
      * The timezone for <i>Alaska Daylight Time</i>.
    */
    LOGC4_TZ_AKDT,
    /**
      * The timezone for <i>Alaska Standard Time</i>.
    */
    LOGC4_TZ_AKST,
    /**
      * The timezone for <i>Alma-Ata Time</i>.
    */
    LOGC4_TZ_ALMT,
    /**
      * The timezone for <i>Armenia Daylight Time</i>.
    */
    LOGC4_TZ_AMDT,
    /**
      * The timezone for <i>Amazon Summer Time</i>.
    */
    LOGC4_TZ_AMST1,
    /**
      * The timezone for <i>Armenia Summer Time</i>.
    */
    LOGC4_TZ_AMST2,
    /**
      * The timezone for <i>Amazon Time</i>.
    */
    LOGC4_TZ_AMT1,
    /**
      * The timezone for <i>Armenia Time</i>.
    */
    LOGC4_TZ_AMT2,
    /**
      * The timezone for <i>Anadyr Summer Time</i>.
    */
    LOGC4_TZ_ANAST,
    /**
      * The timezone for <i>Anadyr Time</i>.
    */
    LOGC4_TZ_ANAT,
    /**
      * The timezone for <i>Aqtobe Time</i>.
    */
    LOGC4_TZ_AQTT,
    /**
      * The timezone for <i>Argentina Time</i>.
    */
    LOGC4_TZ_ART,
    /**
      * The timezone for <i>Arabia Standard Time</i>.
    */
    LOGC4_TZ_AST1,
    /**
      * The timezone for <i>Atlantic Standard Time</i>.
    */
    LOGC4_TZ_AST2,
    /**
      * The timezone for <i>Arabia Summer Time</i>.
    */
    LOGC4_TZ_AST3,
    /**
      * The timezone for <i>Atlantic Summer Time</i>.
    */
    LOGC4_TZ_AST4,
    /**
      * The timezone for <i>Arabic Standard Time</i>.
    */
    LOGC4_TZ_AST5,
    /**
      * The timezone for <i>Al Manamah Standard Time</i>.
    */
    LOGC4_TZ_AST6,
    /**
      * The timezone for <i>Tiempo Estándar del Atlántico</i>.
    */
    LOGC4_TZ_AST7,
    /**
      * The timezone for <i>Atlantic Time</i>.
    */
    LOGC4_TZ_AT1,
    /**
      * The timezone for <i>Alaska Time</i>.
    */
    LOGC4_TZ_AT2,
    /**
      * The timezone for <i>Atlantic Time</i>.
    */
    LOGC4_TZ_AT3,
    /**
      * The timezone for <i>Australian Western Daylight Time</i>.
    */
    LOGC4_TZ_AWDT,
    /**
      * The timezone for <i>Australian Western Standard Time</i>.
    */
    LOGC4_TZ_AWST,
    /**
      * The timezone for <i>Azores Daylight Time</i>.
    */
    LOGC4_TZ_AZODT,
    /**
      * The timezone for <i>Azores Summer Time</i>.
    */
    LOGC4_TZ_AZOST1,
    /**
      * The timezone for <i>Azores Standard Time</i>.
    */
    LOGC4_TZ_AZOST2,
    /**
      * The timezone for <i>Azores Time</i>.
    */
    LOGC4_TZ_AZOT,
    /**
      * The timezone for <i>Azerbaijan Summer Time</i>.
    */
    LOGC4_TZ_AZST,
    /**
      * The timezone for <i>Azerbaijan Time</i>.
    */
    LOGC4_TZ_AZT,
    /**
      * The timezone for <i>Anywhere on Earth</i>.
    */
    LOGC4_TZ_AoE,
    /**
      * The timezone for <i>Bravo Time Zone</i>.
    */
    LOGC4_TZ_B,
    /**
      * The timezone for <i>British Daylight Saving Time</i>.
    */
    LOGC4_TZ_BDST,
    /**
      * The timezone for <i>Brunei Time</i>.
    */
    LOGC4_TZ_BDT1,
    /**
      * The timezone for <i>British Daylight Time</i>.
    */
    LOGC4_TZ_BDT2,
    /**
      * The timezone for <i>Brunei Darussalam Time</i>.
    */
    LOGC4_TZ_BNT,
    /**
      * The timezone for <i>Bolivia Time</i>.
    */
    LOGC4_TZ_BOT,
    /**
      * The timezone for <i>Brasília Summer Time</i>.
    */
    LOGC4_TZ_BRST,
    /**
      * The timezone for <i>Brasília Time</i>.
    */
    LOGC4_TZ_BRT,
    /**
      * The timezone for <i>Bangladesh Standard Time</i>.
    */
    LOGC4_TZ_BST1,
    /**
      * The timezone for <i>Bougainville Standard Time</i>.
    */
    LOGC4_TZ_BST2,
    /**
      * The timezone for <i>British Summer Time</i>.
    */
    LOGC4_TZ_BST3,
    /**
      * The timezone for <i>Brazil Summer Time</i>.
    */
    LOGC4_TZ_BST4,
    /**
      * The timezone for <i>Brazilian Summer Time</i>.
    */
    LOGC4_TZ_BST5,
    /**
      * The timezone for <i>Brazil Time</i>.
    */
    LOGC4_TZ_BT1,
    /**
      * The timezone for <i>Brazilian Time</i>.
    */
    LOGC4_TZ_BT2,
    /**
      * The timezone for <i>Bhutan Time</i>.
    */
    LOGC4_TZ_BTT,
    /**
      * The timezone for <i>Charlie Time Zone</i>.
    */
    LOGC4_TZ_C,
    /**
      * The timezone for <i>Casey Time</i>.
    */
    LOGC4_TZ_CAST,
    /**
      * The timezone for <i>Central Africa Time</i>.
    */
    LOGC4_TZ_CAT,
    /**
      * The timezone for <i>Cocos Islands Time</i>.
    */
    LOGC4_TZ_CCT,
    /**
      * The timezone for <i>Central Daylight Savings Time</i>.
    */
    LOGC4_TZ_CDST1,
    /**
      * The timezone for <i>Central Daylight Saving Time</i>.
    */
    LOGC4_TZ_CDST2,
    /**
      * The timezone for <i>Central Daylight Time</i>.
    */
    LOGC4_TZ_CDT1,
    /**
      * The timezone for <i>Cuba Daylight Time</i>.
    */
    LOGC4_TZ_CDT2,
    /**
      * The timezone for <i>Central Daylight Time</i>.
    */
    LOGC4_TZ_CDT3,
    /**
      * The timezone for <i>Chatham Daylight Time</i>.
    */
    LOGC4_TZ_CDT4,
    /**
      * The timezone for <i>Central European Daylight Time</i>.
    */
    LOGC4_TZ_CEDT,
    /**
      * The timezone for <i>Central European Summer Time</i>.
    */
    LOGC4_TZ_CEST,
    /**
      * The timezone for <i>Central European Time</i>.
    */
    LOGC4_TZ_CET1,
    /**
      * The timezone for <i>Central Europe Time</i>.
    */
    LOGC4_TZ_CET2,
    /**
      * The timezone for <i>Chatham Island Daylight Time</i>.
    */
    LOGC4_TZ_CHADT,
    /**
      * The timezone for <i>Chatham Island Standard Time</i>.
    */
    LOGC4_TZ_CHAST,
    /**
      * The timezone for <i>Choibalsan Daylight Saving Time</i>.
    */
    LOGC4_TZ_CHODST,
    /**
      * The timezone for <i>Choibalsan Daylight Time</i>.
    */
    LOGC4_TZ_CHODT,
    /**
      * The timezone for <i>Choibalsan Summer Time</i>.
    */
    LOGC4_TZ_CHOST,
    /**
      * The timezone for <i>Choibalsan Time</i>.
    */
    LOGC4_TZ_CHOT,
    /**
      * The timezone for <i>Chuuk Time</i>.
    */
    LOGC4_TZ_CHUT,
    /**
      * The timezone for <i>Cayman Islands Daylight Saving Time</i>.
    */
    LOGC4_TZ_CIDST,
    /**
      * The timezone for <i>Cayman Islands Standard Time</i>.
    */
    LOGC4_TZ_CIST,
    /**
      * The timezone for <i>Cayman Islands Time</i>.
    */
    LOGC4_TZ_CIT,
    /**
      * The timezone for <i>Cook Island Time</i>.
    */
    LOGC4_TZ_CKT,
    /**
      * The timezone for <i>Chile Daylight Time</i>.
    */
    LOGC4_TZ_CLDT,
    /**
      * The timezone for <i>Chile Summer Time</i>.
    */
    LOGC4_TZ_CLST1,
    /**
      * The timezone for <i>Chile Standard Time</i>.
    */
    LOGC4_TZ_CLST2,
    /**
      * The timezone for <i>Chile Standard Time</i>.
    */
    LOGC4_TZ_CLT,
    /**
      * The timezone for <i>Colombia Time</i>.
    */
    LOGC4_TZ_COT,
    /**
      * The timezone for <i>Central Standard Time</i>.
    */
    LOGC4_TZ_CST1,
    /**
      * The timezone for <i>China Standard Time</i>.
    */
    LOGC4_TZ_CST2,
    /**
      * The timezone for <i>Cuba Standard Time</i>.
    */
    LOGC4_TZ_CST3,
    /**
      * The timezone for <i>Central Standard Time</i>.
    */
    LOGC4_TZ_CST4,
    /**
      * The timezone for <i>Tiempo Central Estándar</i>.
    */
    LOGC4_TZ_CST5,
    /**
      * The timezone for <i>Central Time</i>.
    */
    LOGC4_TZ_CT1,
    /**
      * The timezone for <i>Chile Time</i>.
    */
    LOGC4_TZ_CT2,
    /**
      * The timezone for <i>Central Time</i>.
    */
    LOGC4_TZ_CT3,
    /**
      * The timezone for <i>Cape Verde Time</i>.
    */
    LOGC4_TZ_CVT,
    /**
      * The timezone for <i>Christmas Island Time</i>.
    */
    LOGC4_TZ_CXT,
    /**
      * The timezone for <i>Chamorro Standard Time</i>.
    */
    LOGC4_TZ_ChST,
    /**
      * The timezone for <i>Delta Time Zone</i>.
    */
    LOGC4_TZ_D,
    /**
      * The timezone for <i>Davis Time</i>.
    */
    LOGC4_TZ_DAVT,
    /**
      * The timezone for <i>Dumont-d'Urville Time</i>.
    */
    LOGC4_TZ_DDUT,
    /**
      * The timezone for <i>Echo Time Zone</i>.
    */
    LOGC4_TZ_E,
    /**
      * The timezone for <i>Easter Island Daylight Time</i>.
    */
    LOGC4_TZ_EADT,
    /**
      * The timezone for <i>Easter Island Summer Time</i>.
    */
    LOGC4_TZ_EASST,
    /**
      * The timezone for <i>Easter Island Standard Time</i>.
    */
    LOGC4_TZ_EAST,
    /**
      * The timezone for <i>Eastern Africa Time</i>.
    */
    LOGC4_TZ_EAT1,
    /**
      * The timezone for <i>East Africa Time</i>.
    */
    LOGC4_TZ_EAT2,
    /**
      * The timezone for <i>European Central Summer Time</i>.
    */
    LOGC4_TZ_ECST,
    /**
      * The timezone for <i>Ecuador Time</i>.
    */
    LOGC4_TZ_ECT1,
    /**
      * The timezone for <i>European Central Time</i>.
    */
    LOGC4_TZ_ECT2,
    /**
      * The timezone for <i>Eastern Daylight Saving Time</i>.
    */
    LOGC4_TZ_EDST1,
    /**
      * The timezone for <i>Eastern Daylight Savings Time</i>.
    */
    LOGC4_TZ_EDST2,
    /**
      * The timezone for <i>Eastern Daylight Time</i>.
    */
    LOGC4_TZ_EDT1,
    /**
      * The timezone for <i>Eastern Daylight Time</i>.
    */
    LOGC4_TZ_EDT2,
    /**
      * The timezone for <i>Tiempo de verano del Este</i>.
    */
    LOGC4_TZ_EDT3,
    /**
      * The timezone for <i>Eastern European Daylight Time</i>.
    */
    LOGC4_TZ_EEDT,
    /**
      * The timezone for <i>Eastern European Summer Time</i>.
    */
    LOGC4_TZ_EEST,
    /**
      * The timezone for <i>Eastern European Time</i>.
    */
    LOGC4_TZ_EET,
    /**
      * The timezone for <i>Efate Time</i>.
    */
    LOGC4_TZ_EFATE,
    /**
      * The timezone for <i>Eastern Greenland Summer Time</i>.
    */
    LOGC4_TZ_EGST1,
    /**
      * The timezone for <i>East Greenland Summer Time</i>.
    */
    LOGC4_TZ_EGST2,
    /**
      * The timezone for <i>East Greenland Time</i>.
    */
    LOGC4_TZ_EGT1,
    /**
      * The timezone for <i>Eastern Greenland Time</i>.
    */
    LOGC4_TZ_EGT2,
    /**
      * The timezone for <i>Eastern Standard Time</i>.
    */
    LOGC4_TZ_EST1,
    /**
      * The timezone for <i>Eastern Standard Time</i>.
    */
    LOGC4_TZ_EST2,
    /**
      * The timezone for <i>Eastern Time</i>.
    */
    LOGC4_TZ_ET1,
    /**
      * The timezone for <i>Eastern Time</i>.
    */
    LOGC4_TZ_ET2,
    /**
      * The timezone for <i>Tiempo del Este</i>.
    */
    LOGC4_TZ_ET3,
    /**
      * The timezone for <i>Foxtrot Time Zone</i>.
    */
    LOGC4_TZ_F,
    /**
      * The timezone for <i>Further-Eastern European Time</i>.
    */
    LOGC4_TZ_FET,
    /**
      * The timezone for <i>Fiji Daylight Time</i>.
    */
    LOGC4_TZ_FJDT,
    /**
      * The timezone for <i>Fiji Summer Time</i>.
    */
    LOGC4_TZ_FJST,
    /**
      * The timezone for <i>Fiji Time</i>.
    */
    LOGC4_TZ_FJT,
    /**
      * The timezone for <i>Falkland Island Daylight Time</i>.
    */
    LOGC4_TZ_FKDT,
    /**
      * The timezone for <i>Falkland Islands Summer Time</i>.
    */
    LOGC4_TZ_FKST1,
    /**
      * The timezone for <i>Falkland Island Standard Time</i>.
    */
    LOGC4_TZ_FKST2,
    /**
      * The timezone for <i>Falkland Island Time</i>.
    */
    LOGC4_TZ_FKT,
    /**
      * The timezone for <i>Fernando de Noronha Time</i>.
    */
    LOGC4_TZ_FNT,
    /**
      * The timezone for <i>Golf Time Zone</i>.
    */
    LOGC4_TZ_G,
    /**
      * The timezone for <i>Galapagos Time</i>.
    */
    LOGC4_TZ_GALT,
    /**
      * The timezone for <i>Gambier Time</i>.
    */
    LOGC4_TZ_GAMT1,
    /**
      * The timezone for <i>Gambier Islands Time</i>.
    */
    LOGC4_TZ_GAMT2,
    /**
      * The timezone for <i>Georgia Standard Time</i>.
    */
    LOGC4_TZ_GET,
    /**
      * The timezone for <i>French Guiana Time</i>.
    */
    LOGC4_TZ_GFT,
    /**
      * The timezone for <i>Gilbert Island Time</i>.
    */
    LOGC4_TZ_GILT,
    /**
      * The timezone for <i>Greenwich Mean Time</i>.
    */
    LOGC4_TZ_GMT1,
    /**
      * The timezone for <i>Greenwich Mean Time</i>.
    */
    LOGC4_TZ_GMT2,
    /**
      * The timezone for <i>Gulf Standard Time</i>.
    */
    LOGC4_TZ_GST1,
    /**
      * The timezone for <i>South Georgia Time</i>.
    */
    LOGC4_TZ_GST2,
    /**
      * The timezone for <i>Guam Standard Time</i>.
    */
    LOGC4_TZ_GST3,
    /**
      * The timezone for <i>Greenwich Time</i>.
    */
    LOGC4_TZ_GT,
    /**
      * The timezone for <i>Guyana Time</i>.
    */
    LOGC4_TZ_GYT,
    /**
      * The timezone for <i>Hotel Time Zone</i>.
    */
    LOGC4_TZ_H,
    /**
      * The timezone for <i>Heure Avancée de l'Atlantique</i>.
    */
    LOGC4_TZ_HAA,
    /**
      * The timezone for <i>Heure Avancée du Centre</i>.
    */
    LOGC4_TZ_HAC,
    /**
      * The timezone for <i>Hawaii Daylight Time</i>.
    */
    LOGC4_TZ_HADT,
    /**
      * The timezone for <i>Heure Avancée de l'Est</i>.
    */
    LOGC4_TZ_HAE,
    /**
      * The timezone for <i>Heure Avancée du Pacifique</i>.
    */
    LOGC4_TZ_HAP,
    /**
      * The timezone for <i>Heure Avancée des Rocheuses</i>.
    */
    LOGC4_TZ_HAR,
    /**
      * The timezone for <i>Hawaii-Aleutian Standard Time</i>.
    */
    LOGC4_TZ_HAST,
    /**
      * The timezone for <i>Heure Avancée de Terre-Neuve</i>.
    */
    LOGC4_TZ_HAT,
    /**
      * The timezone for <i>Hawaii-Aleutian Daylight Time</i>.
    */
    LOGC4_TZ_HDT,
    /**
      * The timezone for <i>Hong Kong Time</i>.
    */
    LOGC4_TZ_HKT,
    /**
      * The timezone for <i>Hora Legal de Venezuela</i>.
    */
    LOGC4_TZ_HLV,
    /**
      * The timezone for <i>Heure Normale de l'Atlantique</i>.
    */
    LOGC4_TZ_HNA,
    /**
      * The timezone for <i>Heure Normale du Centre</i>.
    */
    LOGC4_TZ_HNC,
    /**
      * The timezone for <i>Heure Normale de l'Est</i>.
    */
    LOGC4_TZ_HNE,
    /**
      * The timezone for <i>Heure Normale du Pacifique</i>.
    */
    LOGC4_TZ_HNP,
    /**
      * The timezone for <i>Heure Normale des Rocheuses</i>.
    */
    LOGC4_TZ_HNR,
    /**
      * The timezone for <i>Heure Normale de Terre-Neuve</i>.
    */
    LOGC4_TZ_HNT,
    /**
      * The timezone for <i>Hovd Daylight Saving Time</i>.
    */
    LOGC4_TZ_HOVDST,
    /**
      * The timezone for <i>Hovd Daylight Time</i>.
    */
    LOGC4_TZ_HOVDT,
    /**
      * The timezone for <i>Hovd Summer Time</i>.
    */
    LOGC4_TZ_HOVST,
    /**
      * The timezone for <i>Hovd Time</i>.
    */
    LOGC4_TZ_HOVT,
    /**
      * The timezone for <i>Hawaii Standard Time</i>.
    */
    LOGC4_TZ_HST,
    /**
      * The timezone for <i>India Time Zone</i>.
    */
    LOGC4_TZ_I,
    /**
      * The timezone for <i>Indochina Time</i>.
    */
    LOGC4_TZ_ICT,
    /**
      * The timezone for <i>Israel Daylight Time</i>.
    */
    LOGC4_TZ_IDT1,
    /**
      * The timezone for <i>Iran Daylight Time</i>.
    */
    LOGC4_TZ_IDT2,
    /**
      * The timezone for <i>Indian Chagos Time</i>.
    */
    LOGC4_TZ_IOT,
    /**
      * The timezone for <i>Iran Daylight Time</i>.
    */
    LOGC4_TZ_IRDT,
    /**
      * The timezone for <i>Irkutsk Summer Time</i>.
    */
    LOGC4_TZ_IRKST,
    /**
      * The timezone for <i>Irkutsk Time</i>.
    */
    LOGC4_TZ_IRKT,
    /**
      * The timezone for <i>Iran Standard Time</i>.
    */
    LOGC4_TZ_IRST1,
    /**
      * The timezone for <i>Iran Summer Time</i>.
    */
    LOGC4_TZ_IRST2,
    /**
      * The timezone for <i>India Standard Time</i>.
    */
    LOGC4_TZ_IST1,
    /**
      * The timezone for <i>Irish Standard Time</i>.
    */
    LOGC4_TZ_IST2,
    /**
      * The timezone for <i>Israel Standard Time</i>.
    */
    LOGC4_TZ_IST3,
    /**
      * The timezone for <i>Indian Standard Time</i>.
    */
    LOGC4_TZ_IST4,
    /**
      * The timezone for <i>Irish Summer Time</i>.
    */
    LOGC4_TZ_IST5,
    /**
      * The timezone for <i>Iran Time</i>.
    */
    LOGC4_TZ_IT1,
    /**
      * The timezone for <i>India Time</i>.
    */
    LOGC4_TZ_IT2,
    /**
      * The timezone for <i>Japan Standard Time</i>.
    */
    LOGC4_TZ_JST,
    /**
      * The timezone for <i>Kilo Time Zone</i>.
    */
    LOGC4_TZ_K,
    /**
      * The timezone for <i>Kyrgyzstan Time</i>.
    */
    LOGC4_TZ_KGT,
    /**
      * The timezone for <i>Kerguelen</i>.
    */
    LOGC4_TZ_KIT,
    /**
      * The timezone for <i>Kosrae Time</i>.
    */
    LOGC4_TZ_KOST,
    /**
      * The timezone for <i>Krasnoyarsk Summer Time</i>.
    */
    LOGC4_TZ_KRAST,
    /**
      * The timezone for <i>Krasnoyarsk Time</i>.
    */
    LOGC4_TZ_KRAT,
    /**
      * The timezone for <i>Korea Standard Time</i>.
    */
    LOGC4_TZ_KST1,
    /**
      * The timezone for <i>Korean Standard Time</i>.
    */
    LOGC4_TZ_KST2,
    /**
      * The timezone for <i>Korea Time</i>.
    */
    LOGC4_TZ_KT,
    /**
      * The timezone for <i>Kuybyshev Time</i>.
    */
    LOGC4_TZ_KUYT,
    /**
      * The timezone for <i>Lima Time Zone</i>.
    */
    LOGC4_TZ_L,
    /**
      * The timezone for <i>Lord Howe Daylight Time</i>.
    */
    LOGC4_TZ_LHDT,
    /**
      * The timezone for <i>Lord Howe Standard Time</i>.
    */
    LOGC4_TZ_LHST,
    /**
      * The timezone for <i>Line Islands Time</i>.
    */
    LOGC4_TZ_LINT,
    /**
      * The timezone for <i>Mike Time Zone</i>.
    */
    LOGC4_TZ_M,
    /**
      * The timezone for <i>Magadan Summer Time</i>.
    */
    LOGC4_TZ_MAGST1,
    /**
      * The timezone for <i>Magadan Island Summer Time</i>.
    */
    LOGC4_TZ_MAGST2,
    /**
      * The timezone for <i>Magadan Time</i>.
    */
    LOGC4_TZ_MAGT1,
    /**
      * The timezone for <i>Magadan Island Time</i>.
    */
    LOGC4_TZ_MAGT2,
    /**
      * The timezone for <i>Marquesas Time</i>.
    */
    LOGC4_TZ_MART,
    /**
      * The timezone for <i>Mawson Time</i>.
    */
    LOGC4_TZ_MAWT,
    /**
      * The timezone for <i>Moscow Time</i>.
    */
    LOGC4_TZ_MCK,
    /**
      * The timezone for <i>Mountain Daylight Saving Time</i>.
    */
    LOGC4_TZ_MDST,
    /**
      * The timezone for <i>Mountain Daylight Time</i>.
    */
    LOGC4_TZ_MDT,
    /**
      * The timezone for <i>Mitteleuropäische Sommerzeit</i>.
    */
    LOGC4_TZ_MESZ,
    /**
      * The timezone for <i>Mitteleuropäische Zeit</i>.
    */
    LOGC4_TZ_MEZ,
    /**
      * The timezone for <i>Marshall Islands Time</i>.
    */
    LOGC4_TZ_MHT,
    /**
      * The timezone for <i>Myanmar Time</i>.
    */
    LOGC4_TZ_MMT,
    /**
      * The timezone for <i>Moscow Daylight Time</i>.
    */
    LOGC4_TZ_MSD1,
    /**
      * The timezone for <i>Moscow Summer Time</i>.
    */
    LOGC4_TZ_MSD2,
    /**
      * The timezone for <i>Moscow Standard Time</i>.
    */
    LOGC4_TZ_MSK,
    /**
      * The timezone for <i>Mountain Standard Time</i>.
    */
    LOGC4_TZ_MST1,
    /**
      * The timezone for <i>Malaysian Standard Time</i>.
    */
    LOGC4_TZ_MST2,
    /**
      * The timezone for <i>Mountain Time</i>.
    */
    LOGC4_TZ_MT1,
    /**
      * The timezone for <i>Mountain Time</i>.
    */
    LOGC4_TZ_MT2,
    /**
      * The timezone for <i>Mauritius Time</i>.
    */
    LOGC4_TZ_MUT,
    /**
      * The timezone for <i>Maldives Time</i>.
    */
    LOGC4_TZ_MVT,
    /**
      * The timezone for <i>Malaysia Time</i>.
    */
    LOGC4_TZ_MYT,
    /**
      * The timezone for <i>November Time Zone</i>.
    */
    LOGC4_TZ_N,
    /**
      * The timezone for <i>North American Central Daylight Time</i>.
    */
    LOGC4_TZ_NACDT,
    /**
      * The timezone for <i>North American Central Standard Time</i>.
    */
    LOGC4_TZ_NACST,
    /**
      * The timezone for <i>North American Eastern Daylight Time</i>.
    */
    LOGC4_TZ_NAEDT,
    /**
      * The timezone for <i>North American Eastern Standard Time</i>.
    */
    LOGC4_TZ_NAEST,
    /**
      * The timezone for <i>North American Mountain Daylight Time</i>.
    */
    LOGC4_TZ_NAMDT,
    /**
      * The timezone for <i>North American Mountain Standard Time</i>.
    */
    LOGC4_TZ_NAMST,
    /**
      * The timezone for <i>North American Pacific Daylight Time</i>.
    */
    LOGC4_TZ_NAPDT,
    /**
      * The timezone for <i>North American Pacific Standard Time</i>.
    */
    LOGC4_TZ_NAPST,
    /**
      * The timezone for <i>New Caledonia Time</i>.
    */
    LOGC4_TZ_NCT,
    /**
      * The timezone for <i>Newfoundland Daylight Time</i>.
    */
    LOGC4_TZ_NDT,
    /**
      * The timezone for <i>Norfolk Daylight Time</i>.
    */
    LOGC4_TZ_NFDT1,
    /**
      * The timezone for <i>Norfolk Island Daylight Time</i>.
    */
    LOGC4_TZ_NFDT2,
    /**
      * The timezone for <i>Norfolk Time</i>.
    */
    LOGC4_TZ_NFT1,
    /**
      * The timezone for <i>Norfolk Island Time</i>.
    */
    LOGC4_TZ_NFT2,
    /**
      * The timezone for <i>Novosibirsk Summer Time</i>.
    */
    LOGC4_TZ_NOVST1,
    /**
      * The timezone for <i>Novosibirsk Summer Time</i>.
    */
    LOGC4_TZ_NOVST2,
    /**
      * The timezone for <i>Novosibirsk Time</i>.
    */
    LOGC4_TZ_NOVT1,
    /**
      * The timezone for <i>Novosibirsk Time</i>.
    */
    LOGC4_TZ_NOVT2,
    /**
      * The timezone for <i>Nepal Time</i>.
    */
    LOGC4_TZ_NPT,
    /**
      * The timezone for <i>Nauru Time</i>.
    */
    LOGC4_TZ_NRT,
    /**
      * The timezone for <i>Newfoundland Standard Time</i>.
    */
    LOGC4_TZ_NST,
    /**
      * The timezone for <i>Niue Time</i>.
    */
    LOGC4_TZ_NUT,
    /**
      * The timezone for <i>New Zealand Daylight Time</i>.
    */
    LOGC4_TZ_NZDT,
    /**
      * The timezone for <i>New Zealand Standard Time</i>.
    */
    LOGC4_TZ_NZST,
    /**
      * The timezone for <i>Oscar Time Zone</i>.
    */
    LOGC4_TZ_O,
    /**
      * The timezone for <i>Osteuropäische Sommerzeit</i>.
    */
    LOGC4_TZ_OESZ,
    /**
      * The timezone for <i>Osteuropäische Zeit</i>.
    */
    LOGC4_TZ_OEZ,
    /**
      * The timezone for <i>Omsk Summer Time</i>.
    */
    LOGC4_TZ_OMSST1,
    /**
      * The timezone for <i>Omsk Summer Time</i>.
    */
    LOGC4_TZ_OMSST2,
    /**
      * The timezone for <i>Omsk Standard Time</i>.
    */
    LOGC4_TZ_OMST1,
    /**
      * The timezone for <i>Omsk Standard Time</i>.
    */
    LOGC4_TZ_OMST2,
    /**
      * The timezone for <i>Omsk Time</i>.
    */
    LOGC4_TZ_OMST3,
    /**
      * The timezone for <i>Oral Time</i>.
    */
    LOGC4_TZ_ORAT,
    /**
      * The timezone for <i>Papa Time Zone</i>.
    */
    LOGC4_TZ_P,
    /**
      * The timezone for <i>Pacific Daylight Saving Time</i>.
    */
    LOGC4_TZ_PDST,
    /**
      * The timezone for <i>Pacific Daylight Time</i>.
    */
    LOGC4_TZ_PDT,
    /**
      * The timezone for <i>Peru Time</i>.
    */
    LOGC4_TZ_PET,
    /**
      * The timezone for <i>Kamchatka Summer Time</i>.
    */
    LOGC4_TZ_PETST,
    /**
      * The timezone for <i>Kamchatka Time</i>.
    */
    LOGC4_TZ_PETT1,
    /**
      * The timezone for <i>Petropavlovsk-Kamchatski Time</i>.
    */
    LOGC4_TZ_PETT2,
    /**
      * The timezone for <i>Papua New Guinea Time</i>.
    */
    LOGC4_TZ_PGT,
    /**
      * The timezone for <i>Phoenix Island Time</i>.
    */
    LOGC4_TZ_PHOT,
    /**
      * The timezone for <i>Philippine Time</i>.
    */
    LOGC4_TZ_PHT,
    /**
      * The timezone for <i>Pakistan Standard Time</i>.
    */
    LOGC4_TZ_PKT1,
    /**
      * The timezone for <i>Pakistan Time</i>.
    */
    LOGC4_TZ_PKT2,
    /**
      * The timezone for <i>Pierre & Miquelon Daylight Time</i>.
    */
    LOGC4_TZ_PMDT,
    /**
      * The timezone for <i>Pierre & Miquelon Standard Time</i>.
    */
    LOGC4_TZ_PMST,
    /**
      * The timezone for <i>Pohnpei Standard Time</i>.
    */
    LOGC4_TZ_PONT,
    /**
      * The timezone for <i>Pacific Standard Time</i>.
    */
    LOGC4_TZ_PST1,
    /**
      * The timezone for <i>Pitcairn Standard Time</i>.
    */
    LOGC4_TZ_PST2,
    /**
      * The timezone for <i>Philippine Standard Time</i>.
    */
    LOGC4_TZ_PST3,
    /**
      * The timezone for <i>Pacific Time</i>.
    */
    LOGC4_TZ_PT1,
    /**
      * The timezone for <i>Pacific Time</i>.
    */
    LOGC4_TZ_PT2,
    /**
      * The timezone for <i>Tiempo del Pacífico</i>.
    */
    LOGC4_TZ_PT3,
    /**
      * The timezone for <i>Palau Time</i>.
    */
    LOGC4_TZ_PWT,
    /**
      * The timezone for <i>Paraguay Summer Time</i>.
    */
    LOGC4_TZ_PYST1,
    /**
      * The timezone for <i>Pyongyang Standard Time</i>.
    */
    LOGC4_TZ_PYST2,
    /**
      * The timezone for <i>Paraguay Time</i>.
    */
    LOGC4_TZ_PYT1,
    /**
      * The timezone for <i>Pyongyang Time</i>.
    */
    LOGC4_TZ_PYT2,
    /**
      * The timezone for <i>Quebec Time Zone</i>.
    */
    LOGC4_TZ_Q,
    /**
      * The timezone for <i>Qyzylorda Time</i>.
    */
    LOGC4_TZ_QYZT,
    /**
      * The timezone for <i>Romeo Time Zone</i>.
    */
    LOGC4_TZ_R,
    /**
      * The timezone for <i>Reunion Time</i>.
    */
    LOGC4_TZ_RET,
    /**
      * The timezone for <i>Rothera Time</i>.
    */
    LOGC4_TZ_ROTT,
    /**
      * The timezone for <i>Sierra Time Zone</i>.
    */
    LOGC4_TZ_S,
    /**
      * The timezone for <i>Sakhalin Time</i>.
    */
    LOGC4_TZ_SAKT,
    /**
      * The timezone for <i>Samara Summer Time</i>.
    */
    LOGC4_TZ_SAMST,
    /**
      * The timezone for <i>Samara Time</i>.
    */
    LOGC4_TZ_SAMT1,
    /**
      * The timezone for <i>Samara Standard Time</i>.
    */
    LOGC4_TZ_SAMT2,
    /**
      * The timezone for <i>South Africa Standard Time</i>.
    */
    LOGC4_TZ_SAST1,
    /**
      * The timezone for <i>South African Standard Time</i>.
    */
    LOGC4_TZ_SAST2,
    /**
      * The timezone for <i>Solomon Islands Time</i>.
    */
    LOGC4_TZ_SBT1,
    /**
      * The timezone for <i>Solomon Island Time</i>.
    */
    LOGC4_TZ_SBT2,
    /**
      * The timezone for <i>Seychelles Time</i>.
    */
    LOGC4_TZ_SCT,
    /**
      * The timezone for <i>Singapore Time</i>.
    */
    LOGC4_TZ_SGT,
    /**
      * The timezone for <i>Srednekolymsk Time</i>.
    */
    LOGC4_TZ_SRET,
    /**
      * The timezone for <i>Suriname Time</i>.
    */
    LOGC4_TZ_SRT,
    /**
      * The timezone for <i>Samoa Standard Time</i>.
    */
    LOGC4_TZ_SST1,
    /**
      * The timezone for <i>Singapore Standard Time</i>.
    */
    LOGC4_TZ_SST2,
    /**
      * The timezone for <i>Samoa Time</i>.
    */
    LOGC4_TZ_ST,
    /**
      * The timezone for <i>Syowa Time</i>.
    */
    LOGC4_TZ_SYOT,
    /**
      * The timezone for <i>Tango Time Zone</i>.
    */
    LOGC4_TZ_T,
    /**
      * The timezone for <i>Tahiti Time</i>.
    */
    LOGC4_TZ_TAHT,
    /**
      * The timezone for <i>French Southern and Antarctic Time</i>.
    */
    LOGC4_TZ_TFT,
    /**
      * The timezone for <i>Tajikistan Time</i>.
    */
    LOGC4_TZ_TJT,
    /**
      * The timezone for <i>Tokelau Time</i>.
    */
    LOGC4_TZ_TKT,
    /**
      * The timezone for <i>East Timor Time</i>.
    */
    LOGC4_TZ_TLT,
    /**
      * The timezone for <i>Turkmenistan Time</i>.
    */
    LOGC4_TZ_TMT,
    /**
      * The timezone for <i>Tonga Summer Time</i>.
    */
    LOGC4_TZ_TOST,
    /**
      * The timezone for <i>Tonga Time</i>.
    */
    LOGC4_TZ_TOT,
    /**
      * The timezone for <i>Turkey Time</i>.
    */
    LOGC4_TZ_TRT,
    /**
      * The timezone for <i>Tuvalu Time</i>.
    */
    LOGC4_TZ_TVT,
    /**
      * The timezone for <i>Uniform Time Zone</i>.
    */
    LOGC4_TZ_U,
    /**
      * The timezone for <i>Ulaanbaatar Summer Time</i>.
    */
    LOGC4_TZ_ULAST1,
    /**
      * The timezone for <i>Ulan Bator Summer Time</i>.
    */
    LOGC4_TZ_ULAST2,
    /**
      * The timezone for <i>Ulaanbaatar Time</i>.
    */
    LOGC4_TZ_ULAT1,
    /**
      * The timezone for <i>Ulan Bator Time</i>.
    */
    LOGC4_TZ_ULAT2,
    /**
      * The timezone for <i>Uruguay Summer Time</i>.
    */
    LOGC4_TZ_UYST,
    /**
      * The timezone for <i>Uruguay Time</i>.
    */
    LOGC4_TZ_UYT,
    /**
      * The timezone for <i>Uzbekistan Time</i>.
    */
    LOGC4_TZ_UZT,
    /**
      * The timezone for <i>Victor Time Zone</i>.
    */
    LOGC4_TZ_V,
    /**
      * The timezone for <i>Venezuelan Standard Time</i>.
    */
    LOGC4_TZ_VET,
    /**
      * The timezone for <i>Vladivostok Summer Time</i>.
    */
    LOGC4_TZ_VLAST,
    /**
      * The timezone for <i>Vladivostok Time</i>.
    */
    LOGC4_TZ_VLAT,
    /**
      * The timezone for <i>Vostok Time</i>.
    */
    LOGC4_TZ_VOST,
    /**
      * The timezone for <i>Vanuatu Time</i>.
    */
    LOGC4_TZ_VUT,
    /**
      * The timezone for <i>Whiskey Time Zone</i>.
    */
    LOGC4_TZ_W,
    /**
      * The timezone for <i>Wake Time</i>.
    */
    LOGC4_TZ_WAKT,
    /**
      * The timezone for <i>Western Argentine Summer Time</i>.
    */
    LOGC4_TZ_WARST,
    /**
      * The timezone for <i>West Africa Summer Time</i>.
    */
    LOGC4_TZ_WAST,
    /**
      * The timezone for <i>West Africa Time</i>.
    */
    LOGC4_TZ_WAT1,
    /**
      * The timezone for <i>Western Australia Time</i>.
    */
    LOGC4_TZ_WAT2,
    /**
      * The timezone for <i>Western Daylight Time</i>.
    */
    LOGC4_TZ_WDT,
    /**
      * The timezone for <i>Western European Daylight Time</i>.
    */
    LOGC4_TZ_WEDT,
    /**
      * The timezone for <i>Western European Summer Time</i>.
    */
    LOGC4_TZ_WEST,
    /**
      * The timezone for <i>Westeuropäische Sommerzeit</i>.
    */
    LOGC4_TZ_WESZ,
    /**
      * The timezone for <i>Western European Time</i>.
    */
    LOGC4_TZ_WET,
    /**
      * The timezone for <i>Westeuropäische Zeit</i>.
    */
    LOGC4_TZ_WEZ,
    /**
      * The timezone for <i>Wallis and Futuna Time</i>.
    */
    LOGC4_TZ_WFT,
    /**
      * The timezone for <i>Western Greenland Summer Time</i>.
    */
    LOGC4_TZ_WGST1,
    /**
      * The timezone for <i>West Greenland Summer Time</i>.
    */
    LOGC4_TZ_WGST2,
    /**
      * The timezone for <i>Western Greenland Time</i>.
    */
    LOGC4_TZ_WGT1,
    /**
      * The timezone for <i>Western Greenland Time</i>.
    */
    LOGC4_TZ_WGT2,
    /**
      * The timezone for <i>Western Indonesian Time</i>.
    */
    LOGC4_TZ_WIB1,
    /**
      * The timezone for <i>Waktu Indonesia Barat</i>.
    */
    LOGC4_TZ_WIB2,
    /**
      * The timezone for <i>Eastern Indonesian Time</i>.
    */
    LOGC4_TZ_WIT1,
    /**
      * The timezone for <i>Waktu Indonesia Timur</i>.
    */
    LOGC4_TZ_WIT2,
    /**
      * The timezone for <i>Central Indonesian Time</i>.
    */
    LOGC4_TZ_WITA1,
    /**
      * The timezone for <i>Waktu Indonesia Tengah</i>.
    */
    LOGC4_TZ_WITA2,
    /**
      * The timezone for <i>West Samoa Time</i>.
    */
    LOGC4_TZ_WST1,
    /**
      * The timezone for <i>Western Sahara Summer Time</i>.
    */
    LOGC4_TZ_WST2,
    /**
      * The timezone for <i>Western Summer Time</i>.
    */
    LOGC4_TZ_WST3,
    /**
      * The timezone for <i>Western Standard Time</i>.
    */
    LOGC4_TZ_WST4,
    /**
      * The timezone for <i>Western Sahara Standard Time</i>.
    */
    LOGC4_TZ_WT1,
    /**
      * The timezone for <i>Western Sahara Time</i>.
    */
    LOGC4_TZ_WT2,
    /**
      * The timezone for <i>X-ray Time Zone</i>.
    */
    LOGC4_TZ_X,
    /**
      * The timezone for <i>Yankee Time Zone</i>.
    */
    LOGC4_TZ_Y,
    /**
      * The timezone for <i>Yakutsk Summer Time</i>.
    */
    LOGC4_TZ_YAKST,
    /**
      * The timezone for <i>Yakutsk Time</i>.
    */
    LOGC4_TZ_YAKT,
    /**
      * The timezone for <i>Yap Time</i>.
    */
    LOGC4_TZ_YAPT,
    /**
      * The timezone for <i>Yekaterinburg Summer Time</i>.
    */
    LOGC4_TZ_YEKST,
    /**
      * The timezone for <i>Yekaterinburg Time</i>.
    */
    LOGC4_TZ_YEKT,
    /**
      * The timezone for <i>Zulu Time Zone</i>.
    */
    LOGC4_TZ_Z
} logc4_tz_t;

/**
  * @brief A struct that contains the relevant information for a timezone.
  *
  * All relevant information such as offset from @a UTC and the abbreviation
  * are stored.
*/
struct TZInfo{
    /**
      * The abbreviation of the timezone.
    */
    char *abbreviation;
    /**
      * The name of the timezone.
    */
    char *name;
    /**
      * The language of the name for the timezone.
    */
    char *language;
    /**
      * The locations of the timezone.
    */
    char locations[LOCATIONS_ARR_LEN][LOCATIONS_STR_LEN + 1];
    /**
      * The offset from @a UTC.
    */
    struct{
        /**
          * Whether Daylight Savings Time (DST) is observed in the timezone.
        */
        bool dst;
        /**
          * Whether the  offset is west or east of @a UTC.
        */
        bool west;
        /**
          * The hour offset from @a UTC.
        */
        int hour;
        /**
          * The minute offset from @a UTC.
        */
        int minute;
    } offset;
};

/**
  * An array of @a TZInfo structs. These values are taken from
  * <a href="https://www.timeanddate.com/time/zones/">timeanddate.com</a>. See
  * this for all additional information.
*/
static const struct TZInfo TZS[TZS_LEN] = {
    {
        .abbreviation = "UTC",
        .name = "Coordinated Universal Time",
        .language = "English",
        .locations = {
            "Worldwide"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "A",
        .name = "Alfa Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "ACDT",
        .name = "Australian Central Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 30
        }
    },
    {
        .abbreviation = "ACST",
        .name = "Australian Central Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 30
        }
    },
    {
        .abbreviation = "ACT",
        .name = "Acre Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "ACT",
        .name = "Australian Central Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = true,
            .west = false,
            .hour = 9,
            .minute = 30
        }
    },
    {
        .abbreviation = "ACWST",
        .name = "Australian Central Western Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 45
        }
    },
    {
        .abbreviation = "ADST",
        .name = "Atlantic Daylight Saving Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "ADST",
        .name = "Alaska Daylight Saving Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "ADT",
        .name = "Arabia Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "ADT",
        .name = "Atlantic Daylight Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AEDT",
        .name = "Australian Eastern Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "AEST",
        .name = "Australian Eastern Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "AET",
        .name = "Australian Eastern Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = true,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "AET",
        .name = "Australian Eastern Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "AFT",
        .name = "Afghanistan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 30
        }
    },
    {
        .abbreviation = "AKDT",
        .name = "Alaska Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "AKST",
        .name = "Alaska Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "ALMT",
        .name = "Alma-Ata Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "AMDT",
        .name = "Armenia Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "AMST",
        .name = "Amazon Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AMST",
        .name = "Armenia Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "AMT",
        .name = "Amazon Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AMT",
        .name = "Armenia Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "ANAST",
        .name = "Anadyr Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "ANAT",
        .name = "Anadyr Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "AQTT",
        .name = "Aqtobe Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "ART",
        .name = "Argentina Time",
        .language = "English",
        .locations = {
            "Antarctica",
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Arabia Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Atlantic Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Arabia Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Atlantic Summer Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Arabic Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Al Manamah Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "AST",
        .name = "Tiempo Estándar del Atlántico",
        .language = "Spanish",
        .locations = {
            "North America",
            "Atlantic",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AT",
        .name = "Atlantic Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic"
        },
        .offset = {
            .dst = true,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AT",
        .name = "Alaska Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "AT",
        .name = "Atlantic Time",
        .language = "English",
        .locations = {
            "North America",
            "Atlantic",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AWDT",
        .name = "Australian Western Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "AWST",
        .name = "Australian Western Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZODT",
        .name = "Azores Daylight Time",
        .language = "English",
        .locations = {
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZOST",
        .name = "Azores Summer Time",
        .language = "English",
        .locations = {
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZOST",
        .name = "Azores Standard Time",
        .language = "English",
        .locations = {
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZOT",
        .name = "Azores Time",
        .language = "English",
        .locations = {
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZST",
        .name = "Azerbaijan Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "AZT",
        .name = "Azerbaijan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "AoE",
        .name = "Anywhere on Earth",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "B",
        .name = "Bravo Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "BDST",
        .name = "British Daylight Saving Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "BDT",
        .name = "Brunei Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "BDT",
        .name = "British Daylight Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "BNT",
        .name = "Brunei Darussalam Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "BOT",
        .name = "Bolivia Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "BRST",
        .name = "Brasília Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "BRT",
        .name = "Brasília Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "BST",
        .name = "Bangladesh Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "BST",
        .name = "Bougainville Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "BST",
        .name = "British Summer Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "BST",
        .name = "Brazil Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "BST",
        .name = "Brazilian Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "BT",
        .name = "Brazil Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "BT",
        .name = "Brazilian Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "BTT",
        .name = "Bhutan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "C",
        .name = "Charlie Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "CAST",
        .name = "Casey Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "CAT",
        .name = "Central Africa Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "CCT",
        .name = "Cocos Islands Time",
        .language = "English",
        .locations = {
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 30
        }
    },
    {
        .abbreviation = "CDST",
        .name = "Central Daylight Savings Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 30
        }
    },
    {
        .abbreviation = "CDST",
        .name = "Central Daylight Saving Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CDT",
        .name = "Central Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CDT",
        .name = "Cuba Daylight Time",
        .language = "English",
        .locations = {
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "CDT",
        .name = "Central Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 30
        }
    },
    {
        .abbreviation = "CDT",
        .name = "Chatham Daylight Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 45
        }
    },
    {
        .abbreviation = "CEDT",
        .name = "Central European Daylight Time",
        .language = "English",
        .locations = {
            "Europe",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "CEST",
        .name = "Central European Summer Time",
        .language = "English",
        .locations = {
            "Europe",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "CET",
        .name = "Central European Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "CET",
        .name = "Central Europe Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "CHADT",
        .name = "Chatham Island Daylight Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 45
        }
    },
    {
        .abbreviation = "CHAST",
        .name = "Chatham Island Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 45
        }
    },
    {
        .abbreviation = "CHODST",
        .name = "Choibalsan Daylight Saving Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "CHODT",
        .name = "Choibalsan Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "CHOST",
        .name = "Choibalsan Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "CHOT",
        .name = "Choibalsan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "CHUT",
        .name = "Chuuk Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "CIDST",
        .name = "Cayman Islands Daylight Saving Time",
        .language = "English",
        .locations = {
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "CIST",
        .name = "Cayman Islands Standard Time",
        .language = "English",
        .locations = {
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CIT",
        .name = "Cayman Islands Time",
        .language = "English",
        .locations = {
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CKT",
        .name = "Cook Island Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "CLDT",
        .name = "Chile Daylight Time",
        .language = "English",
        .locations = {
            "South America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "CLST",
        .name = "Chile Summer Time",
        .language = "English",
        .locations = {
            "South America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "CLST",
        .name = "Chile Standard Time",
        .language = "English",
        .locations = {
            "South America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "CLT",
        .name = "Chile Standard Time",
        .language = "English",
        .locations = {
            "South America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "COT",
        .name = "Colombia Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CST",
        .name = "Central Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "CST",
        .name = "China Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "CST",
        .name = "Cuba Standard Time",
        .language = "English",
        .locations = {
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "CST",
        .name = "Central Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 30
        }
    },
    {
        .abbreviation = "CST",
        .name = "Tiempo Central Estándar",
        .language = "Spanish",
        .locations = {
            "North America",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "CT",
        .name = "Central Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = true,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "CT",
        .name = "Chile Time",
        .language = "English",
        .locations = {
            "South America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "CT",
        .name = "Central Time",
        .language = "English",
        .locations = {
            "North America",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "CVT",
        .name = "Cape Verde Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "CXT",
        .name = "Christmas Island Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "ChST",
        .name = "Chamorro Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "D",
        .name = "Delta Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "DAVT",
        .name = "Davis Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "DDUT",
        .name = "Dumont-d'Urville Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "E",
        .name = "Echo Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "EADT",
        .name = "Easter Island Daylight Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "EASST",
        .name = "Easter Island Summer Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "EAST",
        .name = "Easter Island Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "EAT",
        .name = "Eastern Africa Time",
        .language = "English",
        .locations = {
            "Africa",
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "EAT",
        .name = "East Africa Time",
        .language = "English",
        .locations = {
            "Africa",
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "ECST",
        .name = "European Central Summer Time",
        .language = "English",
        .locations = {
            "Europe",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "ECT",
        .name = "Ecuador Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "ECT",
        .name = "European Central Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "EDST",
        .name = "Eastern Daylight Saving Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "EDST",
        .name = "Eastern Daylight Savings Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "EDT",
        .name = "Eastern Daylight Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "EDT",
        .name = "Eastern Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "EDT",
        .name = "Tiempo de verano del Este",
        .language = "Spanish",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "EEDT",
        .name = "Eastern European Daylight Time",
        .language = "English",
        .locations = {
            "Europe",
            "Asia",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "EEST",
        .name = "Eastern European Summer Time",
        .language = "English",
        .locations = {
            "Europe",
            "Asia",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "EET",
        .name = "Eastern European Time",
        .language = "English",
        .locations = {
            "Europe",
            "Asia",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "EFATE",
        .name = "Efate Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "EGST",
        .name = "Eastern Greenland Summer Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "EGST",
        .name = "East Greenland Summer Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "EGT",
        .name = "East Greenland Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "EGT",
        .name = "Eastern Greenland Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "EST",
        .name = "Eastern Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "EST",
        .name = "Eastern Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "ET",
        .name = "Eastern Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = true,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "ET",
        .name = "Eastern Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "ET",
        .name = "Tiempo del Este",
        .language = "Spanish",
        .locations = {
            "North America",
            "Caribbean",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "F",
        .name = "Foxtrot Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "FET",
        .name = "Further-Eastern European Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "FJDT",
        .name = "Fiji Daylight Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "FJST",
        .name = "Fiji Summer Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "FJT",
        .name = "Fiji Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "FKDT",
        .name = "Falkland Island Daylight Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "FKST",
        .name = "Falkland Islands Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "FKST",
        .name = "Falkland Island Standard Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "FKT",
        .name = "Falkland Island Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "FNT",
        .name = "Fernando de Noronha Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "G",
        .name = "Golf Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "GALT",
        .name = "Galapagos Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "GAMT",
        .name = "Gambier Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "GAMT",
        .name = "Gambier Islands Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "GET",
        .name = "Georgia Standard Time",
        .language = "English",
        .locations = {
            "Asia",
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "GFT",
        .name = "French Guiana Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "GILT",
        .name = "Gilbert Island Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "GMT",
        .name = "Greenwich Mean Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa",
            "North America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "GMT",
        .name = "Greenwich Mean Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "GST",
        .name = "Gulf Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "GST",
        .name = "South Georgia Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "GST",
        .name = "Guam Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "GT",
        .name = "Greenwich Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa",
            "North America",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "GYT",
        .name = "Guyana Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "H",
        .name = "Hotel Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAA",
        .name = "Heure Avancée de l'Atlantique",
        .language = "French",
        .locations = {
            "North America",
            "Atlantic"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAC",
        .name = "Heure Avancée du Centre",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "HADT",
        .name = "Hawaii Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAE",
        .name = "Heure Avancée de l'Est",
        .language = "French",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAP",
        .name = "Heure Avancée du Pacifique",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAR",
        .name = "Heure Avancée des Rocheuses",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAST",
        .name = "Hawaii-Aleutian Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "HAT",
        .name = "Heure Avancée de Terre-Neuve",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 30
        }
    },
    {
        .abbreviation = "HDT",
        .name = "Hawaii-Aleutian Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "HKT",
        .name = "Hong Kong Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HLV",
        .name = "Hora Legal de Venezuela",
        .language = "Spanish",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNA",
        .name = "Heure Normale de l'Atlantique",
        .language = "French",
        .locations = {
            "North America",
            "Atlantic",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNC",
        .name = "Heure Normale du Centre",
        .language = "French",
        .locations = {
            "North America",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNE",
        .name = "Heure Normale de l'Est",
        .language = "French",
        .locations = {
            "North America",
            "Caribbean",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNP",
        .name = "Heure Normale du Pacifique",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNR",
        .name = "Heure Normale des Rocheuses",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "HNT",
        .name = "Heure Normale de Terre-Neuve",
        .language = "French",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 30
        }
    },
    {
        .abbreviation = "HOVDST",
        .name = "Hovd Daylight Saving Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HOVDT",
        .name = "Hovd Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HOVST",
        .name = "Hovd Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "HOVT",
        .name = "Hovd Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "HST",
        .name = "Hawaii Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "I",
        .name = "India Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "ICT",
        .name = "Indochina Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "IDT",
        .name = "Israel Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "IDT",
        .name = "Iran Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 30
        }
    },
    {
        .abbreviation = "IOT",
        .name = "Indian Chagos Time",
        .language = "English",
        .locations = {
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "IRDT",
        .name = "Iran Daylight Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 30
        }
    },
    {
        .abbreviation = "IRKST",
        .name = "Irkutsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "IRKT",
        .name = "Irkutsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "IRST",
        .name = "Iran Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 30
        }
    },
    {
        .abbreviation = "IRST",
        .name = "Iran Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 30
        }
    },
    {
        .abbreviation = "IST",
        .name = "India Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 30
        }
    },
    {
        .abbreviation = "IST",
        .name = "Irish Standard Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "IST",
        .name = "Israel Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "IST",
        .name = "Indian Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 30
        }
    },
    {
        .abbreviation = "IST",
        .name = "Irish Summer Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "IT",
        .name = "Iran Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 30
        }
    },
    {
        .abbreviation = "IT",
        .name = "India Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 30
        }
    },
    {
        .abbreviation = "JST",
        .name = "Japan Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "K",
        .name = "Kilo Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "KGT",
        .name = "Kyrgyzstan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "KIT",
        .name = "Kerguelen",
        .language = "Islands",
        .locations = {
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "KOST",
        .name = "Kosrae Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "KRAST",
        .name = "Krasnoyarsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "KRAT",
        .name = "Krasnoyarsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "KST",
        .name = "Korea Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "KST",
        .name = "Korean Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "KT",
        .name = "Korea Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "KUYT",
        .name = "Kuybyshev Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "L",
        .name = "Lima Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "LHDT",
        .name = "Lord Howe Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "LHST",
        .name = "Lord Howe Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 30
        }
    },
    {
        .abbreviation = "LINT",
        .name = "Line Islands Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 14,
            .minute = 0
        }
    },
    {
        .abbreviation = "M",
        .name = "Mike Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "MAGST",
        .name = "Magadan Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "MAGST",
        .name = "Magadan Island Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "MAGT",
        .name = "Magadan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "MAGT",
        .name = "Magadan Island Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "MART",
        .name = "Marquesas Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 30
        }
    },
    {
        .abbreviation = "MAWT",
        .name = "Mawson Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "MCK",
        .name = "Moscow Time",
        .language = "English",
        .locations = {
            "Europe",
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "MDST",
        .name = "Mountain Daylight Saving Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "MDT",
        .name = "Mountain Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "MESZ",
        .name = "Mitteleuropäische Sommerzeit",
        .language = "German",
        .locations = {
            "Europe",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "MEZ",
        .name = "Mitteleuropäische Zeit",
        .language = "German",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "MHT",
        .name = "Marshall Islands Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "MMT",
        .name = "Myanmar Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 30
        }
    },
    {
        .abbreviation = "MSD",
        .name = "Moscow Daylight Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "MSD",
        .name = "Moscow Summer Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "MSK",
        .name = "Moscow Standard Time",
        .language = "English",
        .locations = {
            "Europe",
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "MST",
        .name = "Mountain Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "MST",
        .name = "Malaysian Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "MT",
        .name = "Mountain Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = true,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "MT",
        .name = "Mountain Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "MUT",
        .name = "Mauritius Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "MVT",
        .name = "Maldives Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "MYT",
        .name = "Malaysia Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "N",
        .name = "November Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "NACDT",
        .name = "North American Central Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "NACST",
        .name = "North American Central Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAEDT",
        .name = "North American Eastern Daylight Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAEST",
        .name = "North American Eastern Standard Time",
        .language = "English",
        .locations = {
            "North America",
            "Caribbean",
            "Central America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAMDT",
        .name = "North American Mountain Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAMST",
        .name = "North American Mountain Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAPDT",
        .name = "North American Pacific Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "NAPST",
        .name = "North American Pacific Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "NCT",
        .name = "New Caledonia Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "NDT",
        .name = "Newfoundland Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 30
        }
    },
    {
        .abbreviation = "NFDT",
        .name = "Norfolk Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "NFDT",
        .name = "Norfolk Island Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "NFT",
        .name = "Norfolk Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "NFT",
        .name = "Norfolk Island Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "NOVST",
        .name = "Novosibirsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "NOVST",
        .name = "Novosibirsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "NOVT",
        .name = "Novosibirsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "NOVT",
        .name = "Novosibirsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "NPT",
        .name = "Nepal Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 45
        }
    },
    {
        .abbreviation = "NRT",
        .name = "Nauru Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "NST",
        .name = "Newfoundland Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 30
        }
    },
    {
        .abbreviation = "NUT",
        .name = "Niue Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "NZDT",
        .name = "New Zealand Daylight Time",
        .language = "English",
        .locations = {
            "Pacific",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "NZST",
        .name = "New Zealand Standard Time",
        .language = "English",
        .locations = {
            "Pacific",
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "O",
        .name = "Oscar Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "OESZ",
        .name = "Osteuropäische Sommerzeit",
        .language = "German",
        .locations = {
            "Europe",
            "Asia",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "OEZ",
        .name = "Osteuropäische Zeit",
        .language = "German",
        .locations = {
            "Europe",
            "Asia",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "OMSST",
        .name = "Omsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "OMSST",
        .name = "Omsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "OMST",
        .name = "Omsk Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "OMST",
        .name = "Omsk Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "OMST",
        .name = "Omsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "ORAT",
        .name = "Oral Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "P",
        .name = "Papa Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "PDST",
        .name = "Pacific Daylight Saving Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "PDT",
        .name = "Pacific Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "PET",
        .name = "Peru Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "PETST",
        .name = "Kamchatka Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "PETT",
        .name = "Kamchatka Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "PETT",
        .name = "Petropavlovsk-Kamchatski Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "PGT",
        .name = "Papua New Guinea Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "PHOT",
        .name = "Phoenix Island Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "PHT",
        .name = "Philippine Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PKT",
        .name = "Pakistan Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "PKT",
        .name = "Pakistan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "PMDT",
        .name = "Pierre & Miquelon Daylight Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "PMST",
        .name = "Pierre & Miquelon Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "PONT",
        .name = "Pohnpei Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "PST",
        .name = "Pacific Standard Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PST",
        .name = "Pitcairn Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PST",
        .name = "Philippine Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PT",
        .name = "Pacific Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = true,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PT",
        .name = "Pacific Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PT",
        .name = "Tiempo del Pacífico",
        .language = "Spanish",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "PWT",
        .name = "Palau Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "PYST",
        .name = "Paraguay Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "PYST",
        .name = "Pyongyang Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 30
        }
    },
    {
        .abbreviation = "PYT",
        .name = "Paraguay Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "PYT",
        .name = "Pyongyang Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 30
        }
    },
    {
        .abbreviation = "Q",
        .name = "Quebec Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "QYZT",
        .name = "Qyzylorda Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "R",
        .name = "Romeo Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "RET",
        .name = "Reunion Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "ROTT",
        .name = "Rothera Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "S",
        .name = "Sierra Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAKT",
        .name = "Sakhalin Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAMST",
        .name = "Samara Summer Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAMT",
        .name = "Samara Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAMT",
        .name = "Samara Standard Time",
        .language = "English",
        .locations = {
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAST",
        .name = "South Africa Standard Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "SAST",
        .name = "South African Standard Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "SBT",
        .name = "Solomon Islands Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "SBT",
        .name = "Solomon Island Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "SCT",
        .name = "Seychelles Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "SGT",
        .name = "Singapore Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "SRET",
        .name = "Srednekolymsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "SRT",
        .name = "Suriname Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "SST",
        .name = "Samoa Standard Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "SST",
        .name = "Singapore Standard Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "ST",
        .name = "Samoa Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "SYOT",
        .name = "Syowa Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "T",
        .name = "Tango Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "TAHT",
        .name = "Tahiti Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "TFT",
        .name = "French Southern and Antarctic Time",
        .language = "English",
        .locations = {
            "Indian Ocean"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "TJT",
        .name = "Tajikistan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "TKT",
        .name = "Tokelau Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "TLT",
        .name = "East Timor Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "TMT",
        .name = "Turkmenistan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "TOST",
        .name = "Tonga Summer Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 14,
            .minute = 0
        }
    },
    {
        .abbreviation = "TOT",
        .name = "Tonga Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "TRT",
        .name = "Turkey Time",
        .language = "English",
        .locations = {
            "Asia",
            "Europe"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "TVT",
        .name = "Tuvalu Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "U",
        .name = "Uniform Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "ULAST",
        .name = "Ulaanbaatar Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "ULAST",
        .name = "Ulan Bator Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "ULAT",
        .name = "Ulaanbaatar Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "ULAT",
        .name = "Ulan Bator Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "UYST",
        .name = "Uruguay Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "UYT",
        .name = "Uruguay Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "UZT",
        .name = "Uzbekistan Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "V",
        .name = "Victor Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "VET",
        .name = "Venezuelan Standard Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 4,
            .minute = 0
        }
    },
    {
        .abbreviation = "VLAST",
        .name = "Vladivostok Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "VLAT",
        .name = "Vladivostok Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "VOST",
        .name = "Vostok Time",
        .language = "English",
        .locations = {
            "Antarctica"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "VUT",
        .name = "Vanuatu Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "W",
        .name = "Whiskey Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "WAKT",
        .name = "Wake Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "WARST",
        .name = "Western Argentine Summer Time",
        .language = "English",
        .locations = {
            "South America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 3,
            .minute = 0
        }
    },
    {
        .abbreviation = "WAST",
        .name = "West Africa Summer Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "WAT",
        .name = "West Africa Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WAT",
        .name = "Western Australia Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "WDT",
        .name = "Western Daylight Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "WEDT",
        .name = "Western European Daylight Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WEST",
        .name = "Western European Summer Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WESZ",
        .name = "Westeuropäische Sommerzeit",
        .language = "German",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WET",
        .name = "Western European Time",
        .language = "English",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "WEZ",
        .name = "Westeuropäische Zeit",
        .language = "German",
        .locations = {
            "Europe",
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "WFT",
        .name = "Wallis and Futuna Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "WGST",
        .name = "Western Greenland Summer Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WGST",
        .name = "West Greenland Summer Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WGT",
        .name = "Western Greenland Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "WGT",
        .name = "Western Greenland Time",
        .language = "English",
        .locations = {
            "North America"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 2,
            .minute = 0
        }
    },
    {
        .abbreviation = "WIB",
        .name = "Western Indonesian Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "WIB",
        .name = "Waktu Indonesia Barat",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 7,
            .minute = 0
        }
    },
    {
        .abbreviation = "WIT",
        .name = "Eastern Indonesian Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "WIT",
        .name = "Waktu Indonesia Timur",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "WITA",
        .name = "Central Indonesian Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "WITA",
        .name = "Waktu Indonesia Tengah",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "WST",
        .name = "West Samoa Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 13,
            .minute = 0
        }
    },
    {
        .abbreviation = "WST",
        .name = "Western Sahara Summer Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 1,
            .minute = 0
        }
    },
    {
        .abbreviation = "WST",
        .name = "Western Summer Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "WST",
        .name = "Western Standard Time",
        .language = "English",
        .locations = {
            "Australia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 8,
            .minute = 0
        }
    },
    {
        .abbreviation = "WT",
        .name = "Western Sahara Standard Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "WT",
        .name = "Western Sahara Time",
        .language = "English",
        .locations = {
            "Africa"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    },
    {
        .abbreviation = "X",
        .name = "X-ray Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 11,
            .minute = 0
        }
    },
    {
        .abbreviation = "Y",
        .name = "Yankee Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = true,
            .hour = 12,
            .minute = 0
        }
    },
    {
        .abbreviation = "YAKST",
        .name = "Yakutsk Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "YAKT",
        .name = "Yakutsk Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 9,
            .minute = 0
        }
    },
    {
        .abbreviation = "YAPT",
        .name = "Yap Time",
        .language = "English",
        .locations = {
            "Pacific"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 10,
            .minute = 0
        }
    },
    {
        .abbreviation = "YEKST",
        .name = "Yekaterinburg Summer Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 6,
            .minute = 0
        }
    },
    {
        .abbreviation = "YEKT",
        .name = "Yekaterinburg Time",
        .language = "English",
        .locations = {
            "Asia"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 5,
            .minute = 0
        }
    },
    {
        .abbreviation = "Z",
        .name = "Zulu Time Zone",
        .language = "English",
        .locations = {
            "Military"
        },
        .offset = {
            .dst = false,
            .west = false,
            .hour = 0,
            .minute = 0
        }
    }
};

#undef TZS_LEN
#undef LOCATIONS_ARR_LEN
#undef LOCATIONS_STR_LEN

#endif
