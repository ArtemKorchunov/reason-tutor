// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';


function sum(a, b) {
  return a + b | 0;
}

var $$Math = /* module */[
  /* pi */3.14159,
  /* sum */sum
];

var School = /* module */[];

var who = "I am a student!";

var Circle = /* module */[];

var Game = /* module */[];

function isWon(state) {
  return state === /* Won */0;
}

var VideoGame = /* module */[/* isWon */isWon];

function professionDescription(p) {
  switch (p) {
    case 0 : 
        return "You are abuilder";
    case 1 : 
        return "You are ateacher";
    case 2 : 
        return "You are aprogrammer";
    
  }
}

var Company = /* module */[/* professionDescription */professionDescription];

var onePerson = /* Student */1;

var personTwo = /* record */[
  /* x */1.2,
  /* y */2.2
];

exports.$$Math = $$Math;
exports.School = School;
exports.onePerson = onePerson;
exports.who = who;
exports.Circle = Circle;
exports.personTwo = personTwo;
exports.Game = Game;
exports.VideoGame = VideoGame;
exports.Company = Company;
/* No side effect */