#!/bin/bash
echo "使用Python或原生方式取得清單?"
read -p "(P)ython/(G)eneric : " confirm

if [[ ${confirm} == 'G' ]] ; then
  echo "獲取清單中..."
  curl -Ls http://invoice.etax.nat.gov.tw/ > ./fetch/source.html
  cat ./fetch/source.html | sed 's/spanid/span id/g'  |  tidy -imq --show-errors 0 | grep 'class=".*">[0-9]*<' | \
    sed 's/class=\".*\"//g;s/<h.*>//g;s/[^0-9]//g;5,$ s/\w/:/g;s/\ /:/g;/:/d;/^$/d;s/\ /:/;2 s/^/特別獎：/;3 s/^/特獎：/;4 s/^/增開陸獎：/' \
    > ./fetch/fetch_exp_head
  cat ./fetch/source.html | sed 's/spanid/span id/g'  |  tidy -imq --show-errors 0 | sed 's/、/ /g' | grep '".*">[0-9].*<' | \
    grep 'span' | sed 's/class=\".*\"//g;s/\".*\"//g;s/<.*>//g;s/>//g;4,$ s/[0-9]//g;1,2 s/\ /:/g;4,$ s/\ /:/g;/:/d;s/^[\ ]*/:/g;s/:/頭獎：/;s/ /;/g' \
    > ./fetch/fetch_head
  cat ./fetch/fetch_head >> ./fetch/fetch_exp_head
  mv ./fetch/fetch_exp_head ./fetch/fetch_result.txt
  ./receipt

elif [[ ${confirm} == 'P' ]] ; then
  python2 invoice.py > ./fetch/fetch_result_py.txt
  ./receipt
fi
