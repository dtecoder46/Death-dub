create table gaza_deaths (
  date_of_count date,
  deaths int
);

insert into gaza_deaths values ('2024-06-14', 37266);

insert into gaza_deaths values ('2024-06-16', 37296);

insert into gaza_deaths values ('2024-06-30', 37877);

select * from gaza_deaths
