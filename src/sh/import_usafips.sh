db="test"
host="dbase2"
cd /tmp
wget https://www2.census.gov/geo/tiger/TIGER2017/COUNTY/tl_2017_us_county.zip
unzip tl_2017_us_county.zip
shp2pgsql tl_2017_us_county tl_2017_us_county > tl_2017_us_county.sql
cat tl_2017_us_county.sql | psql $db

copy (
  select tl_2017_us_county.name, geoid as hydrocode, 'usafips' as bundle,
  CASE
    WHEN classfp like 'C%' THEN 'city'
    ELSE 'county'
  END as ftype, 
  st_astext(geom) as wkt
  from tl_2017_us_county 
  left outer join dh_feature 
  on (bundle = 'usafips' and hydrocode = geoid)
  where hydroid is null 
) to '/tmp/tl_2017_us_county.wkt' WITH HEADER CSV DELIMITER AS E'\t';
