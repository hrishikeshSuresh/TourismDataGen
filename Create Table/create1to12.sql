/*Working create table for tables 1-12 */
CREATE TABLE tour_destination(
	country varchar(20) not null,
  name_of_place varchar(20) not null,
  best_time_to_visit varchar(10),
  rating int,
  destination_id varchar(10) primary key
);
 
/*CREATE TABLE tour_operator(
  tour_id varchar(10) primary key,
  name varchar(20) not null,
  package_id varchar(10),
  rating int,
  experience varchar(50)
);*/

CREATE TABLE packages(
  P_ID varchar(20),
  P_Name varchar(20) not null,
  primary key(P_ID,P_Name)
);

CREATE TABLE tour_operator(
  Tour_ID varchar(50),
  Tour_Operator_Name varchar(50) not null,
  Package_ID varchar(50),
  Ratings int,
  Reviews varchar(500),
  primary key(Tour_ID,Package_ID),
  foreign key(Package_ID) references packages(P_ID)
);

CREATE TABLE accomodation(
  accomodation_id varchar(100) primary key,
  cost int not null,
  accomodation_reservation boolean,
  no_of_person int,
  no_of_rooms int,
  name varchar(50) not null,
  type varchar(50) not null
);



CREATE TABLE events(
  name varchar(20) primary key,
  city varchar(20),
  cost_per_person int not null,
  ratings int,
  events_amenities varchar(50),
  start_date date,
  end_date date,
  destination_id varchar(10),
  foreign key(destination_id) references tour_destination(destination_id)
);


CREATE TABLE restaurant(
  restaurant_id varchar(10) primary key,
  name varchar(20) not null,
  city varchar(20) not null,
  cost_per_person int not null,
  restaurant_amenities varchar(50),
  restaurant_reservation boolean
);

CREATE TABLE usertable(
  username varchar(10) unique,
  email varchar(20),
  password varchar(20) not null,
  age int,
  primary key(username)
);


CREATE TABLE train(
  cost int not null,
  train_reservation boolean,
  train_id varchar(10) primary key,
  tier varchar(20) not null,
  source varchar(20) not null,
  destination varchar(20) not null
);

CREATE TABLE airline(
  destination varchar(50) not null,
  source varchar(50) not null,
  airplane_id varchar(50) primary key,
  airline_reservation boolean,
  cost int not null,
  luxury_class varchar(50)
);


CREATE TABLE bus(
  bus_no varchar(10) primary key,
  source varchar(20) not null,
  luxury_class varchar(20),
  cost int not null,
  destination varchar(20) not null
);


CREATE TABLE payment(
  amount int not null,
  mode_of_payment varchar(20) not null,
  payment_no varchar(10) primary key,
  username varchar(20),
  foreign key(username) references usertable(username)
);

CREATE TABLE transport(
  transportation_id varchar(10),
  destination_id varchar(10),
  source varchar(20) not null,
  destination varchar(20) not null,
  primary key(transportation_id,destination_id),
  foreign key(destination_id) references tour_destination(destination_id)
);
