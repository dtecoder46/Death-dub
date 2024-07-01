create table israel_deaths (
  date_of_count date,
  deaths int
);

insert into israel_deaths values ('2024-06-14', 1139);

insert into israel_deaths values ('2024-06-16', 1139);

insert into israel_deaths values ('2024-06-30', 1139);

select * from israel_deaths
where date_of_count = '2024-06-14';
