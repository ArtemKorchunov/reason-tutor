module Math = {
  let pi = 3.14159;
  let sum = (a, b) => a + b;
};

Math.pi;
Math.sum(1, 2);

module School = {
  type profession =
    | Teacher
    | Student;
}

let onePerson = School.Student;

let who =
  School.(
    switch onePerson {
      | Teacher => "I am a teacher!"
      | Student => "I am a student!"
      }  
  );
/* let greeting: string = "I am a student!"; */

/* module name must start with the uppercase */

module Circle = {
  type point = {
    x: float,
    y: float,
  };
}

let personTwo = Circle.{ x: 1.2, y: 2.2 };
/* let center: Circle.point = {Circle.x: 1.2, y: 2.3}}; */

/* open -> Globally open module */
open School;

let personTwo = Teacher;

/* open -> Globally open module */
open Circle;

let personTwo = { x: 1.2, y: 2.2 };


module Game = {
  type states =
    | Won
    | Lose
    | Draw;
};

module VideoGame = {
  include Game;
  let isWon = state => state == Won;
};

VideoGame.isWon(Game.Won);
/* - : bool = true */

/* Module types ------------------------------------------ */

module type EstablishmentType = {
  type profession =
    | Builder
    | Teacher
    | Programmer;
  let professionDescription: profession => string;
};

module Company: EstablishmentType {
  type profession =
    | Builder
    | Teacher
    | Programmer;
  let text = "You are a";
  let professionDescription = p => {
    switch p {
    | Builder => text ++ "builder"
    | Teacher => text ++ "teacher"
    | Programmer => text ++ "programmer"
    };
  }
};

Company.professionDescription(Company.Teacher);
/* You are a teacher */

/* Note! Company.text is not available due to not matching the module type -> (EstablishmentType) */