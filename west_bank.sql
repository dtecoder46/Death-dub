create table west_bank_deaths (
  date_of_count date,
  deaths int
);

insert into west_bank_deaths values ('2024-06-14', 547);

insert into west_bank_deaths values ('2024-06-16', 548);

insert into west_bank_deaths values ('2024-06-30', 553);

select * from west_bank_deaths
