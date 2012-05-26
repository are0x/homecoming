# coding: utf-8

import sys
import unicodedata
import re

def _decode(s):
    for enc in 'utf8 sjis euc-jp cp932'.split():
        try:
            return s.decode(enc)
        except:
            pass
    return None

if __name__ == '__main__':

    if len(sys.argv) < 3: 
        print sys.argv[0], ': ファイル名を指定してください'
        exit(1)

    # r = re.compile(ur'[０-９]')

    with open(sys.argv[1]) as infile:

        cont = _decode(infile.read())
        # k = (r.split(cont)[1::2] + [u''])
        # nk = r.split(cont)[::2]
        # norm = ''.join([''.join((nk, unicodedata.normalize('NFKC', k))) for nk, k in zip(nk, k)])
        norm = unicodedata.normalize('NFKC', cont)

        with open(sys.argv[2], 'w') as outfile:
            outfile.write(norm.replace(u'\t', u' ').replace(u'　', u' ').encode('utf8'))
