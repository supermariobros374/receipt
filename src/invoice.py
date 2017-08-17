# -*- coding: utf-8 -*-`

import urllib2
from sgmllib import SGMLParser
import re
import sys

reload(sys)
sys.setdefaultencoding('utf-8')

# this class is following offical writing... no any meaning
class invoiceList(SGMLParser):
    is_td = ""
    name = []
    def start_td(self, attrs):
        self.is_td = 1
    def end_td(self):
        self.is_td = ""
    def handle_data(self, text):
        if self.is_td:
            self.name.append(text)

def online_get_invoice():

	# open url
    invoiceUrl = "http://invoice.etax.nat.gov.tw/"
    page = urllib2.urlopen(invoiceUrl).read()

	# analysising html
	# it only takes out the label which is <td></td>(table)
    invoice = invoiceList()
    invoice.feed(page)

	# put result inside a string
    data = ""
    for i in invoice.name:
        data += i.decode('utf-8')

	# only take out "a table", ignore leaving table
    data = re.sub("......<td>", "", data)
	
	# only take out the upper part of table
    data = re.sub(u"增開六獎號碼相同者.+", "", data)
	
    invoice_list = re.findall("\d{3,8}", data)

    return invoice_list
