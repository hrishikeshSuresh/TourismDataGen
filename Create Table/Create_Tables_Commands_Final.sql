

DROP TABLE Begin_Place;

CREATE TABLE Begin_Place(
  p_ID varchar(50),
  begin_place varchar(50),
  foreign key(p_ID) references Package(P_ID)
);

DROP TABLE End_Place;

CREATE TABLE End_Place(
  p_ID varchar(50),
  end_place varchar(50),
  foreign key(p_ID) references Package(P_ID)
);

DROP TABLE Tourist_Destination;

CREATE TABLE Tourist_Destination(
  city varchar(50) not null,
  country varchar(50) not null,
  best_visit_time varchar(50),
  ratings int,
  Destination_ID varchar(50) primary key
);

DROP TABLE Tour_Operator;

CREATE TABLE Tour_Operator(
  Tour_ID varchar(50) primary key,
  Tour_Operator_Name varchar(50) not null,
  Package_ID varchar(50),
  Ratings int,
  Reviews varchar(500),
  foreign key(Package_ID) references Package(P_ID)
);

DROP TABLE Accomodation;

CREATE TABLE Accomodation(
  Accomodation_ID varchar(50) primary key,
  Accomodation_Name varchar(50) not null,
  Ratings int,
  Reviews varchar(500),
  City varchar(50) not null
);

DROP TABLE Restaurant;

CREATE TABLE Restaurant(
  Restaurant_ID varchar(50) primary key,
  Restaurant_Name varchar(50) not null,
  Phone_No varchar(50),
  Website_Name varchar(500),
  Cuisine varchar(50) not null,
  City varchar(50) not null
);

DROP TABLE Train;

CREATE TABLE Train(
  Train_ID varchar(50) primary key,
  Source varchar(50) not null,
  Destination varchar(50) not null,
  Type varchar(50),
  Cost int not null
);

DROP TABLE Airline;

CREATE TABLE Airline(
  Airplane_ID varchar(50) primary key,
  Source varchar(50) not null,
  Destination varchar(50) not null,
  Type varchar(50),
  Cost int not null
);

DROP TABLE Bus;

CREATE TABLE Bus(
  Bus_ID varchar(50) primary key,
  Source varchar(50) not null,
  Destination varchar(50) not null,
  Type varchar(50),
  Cost int not null
);

DROP TABLE Transportation;

CREATE TABLE Transportation(
  Transportation_ID varchar(50) primary key,
  Source varchar(50) not null,
  Destination varchar(50) not null
);
