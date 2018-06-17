CREATE TABLE Mode_Of_Transport(
  Airplane_ID varchar(50),
  Train_ID varchar(50),
  Bus_No varchar(50),
  foreign key(Airplane_ID) references Airline(Airplane_ID),
  foreign key(Train_ID) references Train(Train_ID),
  foreign key(Bus_No) references Bus(Bus_ID)
);

CREATE TABLE Package(
  P_ID varchar(50) primary key,
  Package_Name varchar(50) not null
);

CREATE TABLE Events(
  Event_Name varchar(50) not null,
  City varchar(50)
  Ratings int,
  Destination_ID varchar(50) primary key,
  foreign key(Destination_ID) references Tourist_Destination(Destination_ID)
);

CREATE TABLE Restaurant_Present_In(
  Destination_ID varchar(50),
  ID varchar(50),
  primary key(Destination_ID,ID),
  foreign key(Destination_ID) references Tourist_Destination(Destination_ID),
  foreign key(ID) references Restaurant(Restaurant_ID)
);

CREATE TABLE Location(
  Accomodation_ID varchar(50) primary key,
  City varchar(50),
  Country varchar(50),
  foreign key(Accomodation_ID) references Accomodation(Accomodation_ID)
);

CREATE TABLE To_Has_Packages(
  P_ID varchar(50) primary key,
  Tour_ID varchar(50) not null,
  foreign key(P_ID) references Package(P_ID),
  foreign key(Tour_ID) references Tour_Operator(Tour_ID)
);

CREATE TABLE User(
  Username varchar(50) primary key,
  Email varchar(50),
  Password varchar(50) not null,
  Age int
);

CREATE TABLE Payment(
  Payment_No int primary key,
  Username varchar(50) not null,
  Amount int,
  Mode_Of_Payment varchar(50),
  foreign key(Username) references User(Username)
);

CREATE TABLE To_Takes_Payment(
  Tour_ID varchar(50) not null,
  Payment_No int primary key,
  foreign key(Tour_ID) references Tour_Operator(Tour_ID),
  foreign key(Payment_No) references Payment(Payment_No)
);

CREATE TABLE Start_Date(
  p_ID varchar(50) primary key,
  Start_Date date not null,
  foreign key(p_ID) references Package(P_ID)
);

CREATE TABLE End_Date(
  p_ID varchar(50) primary key,
  End_Date date not null,
  foreign key(p_ID) references Package(P_ID)
);
