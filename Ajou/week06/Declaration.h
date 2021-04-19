#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN = 100;
#define TRUE 1
#define FALSE 0
#define EMTRYNUMINVALIDERMSG "입력가능한 100명의 정보가 가득찼습니다!\n"

#define INTRODUCTIONMSG "참가자 정보 관리 프로그램\n"
#define MENUPRINTMSG "\n입력(1), 검색(2), 정보변경(3), 참가취소(4), 종료(5)\n[1부터 5사이 수를 입력해주세요.]\n"
#define INPUTMENUMSG "입력 : "
#define INVALIDMENUMSG "잘못된 입력입니다. 다시입력해주세요!\n"

#define PRINTNAMEMSG "이름\t\t : %s\n"
#define PRINTDATEMSG "신청날짜\t : %d\n"
#define PRINTREGIONMSG "신청지역\t : %s\n"

#define INSERTMSG "\n정보를 입력해주세요.\n"
#define INSERTNAMEMSG "이름(영문 10자이내) : "
#define INSERTDATEMASG "신청날짜(YYYYMMDD) : "
#define INSERTREGION "신청지역(영문 20자이내) : "
#define INSERTOKMSG "입력이 완료되었습니다!\n"
#define INSERTDUPLICATEERRMSG "이미 등록된 이름입니다!\n"
#define INSERTINVALIDNAMEERRMSG "이름을 제대로 입력해주세요!\n"

#define SEARCHMSG "\n검색할 이름을 입력해주세요.\n"
#define SEARCHINPUTNAMEMSG "이름 : "
#define SEARCHOKMSG "검색이 완료되었습니다.\n"
#define SEARCHINVALIDNONAMEERRMSG "일치하는 이름이 없습니다!\n"
#define SEARCHINVALIDAMOUNTERRMSG "검색할 데이터가 없습니다!\n"
#define SEARCHINVALIDNAMEERRMSG "이름을 제대로 입력해주세요!\n"

#define CHANGEDATAMSG "\n변경할 정보를 입력하세요. (이름, 정보)\n"
#define CHANGEINPUTNAMEDATAMSG "이름 정보 : "
#define CHANGEOKMSG "변경이 완료되었습니다.\n"
#define CHANGEINVALIDDATAERRMSG "일치하는 이름이 없습니다!\n"
#define CHANGEINVALIDAMOUNTERRMSG "변경할 데이터가 없습니다!\n"
#define CHANGEINVALIDNAMEERRMSG "이름을 제대로 입력해주세요!\n"

#define CANCELMSG "\n취소할 이름을 입력하세요.\n"
#define CANCELINPUTNAMEMSG "이름 : "
#define CANCELOKMSG "참가가 취소되었습니다.\n"
#define CANCELINVALIDDATAERRMSG "일치하는 이름이 없습니다!\n"
#define CANCELINVALIDAMOUTERRMSG "삭제할 데이터가 없습니다!\n"

#define TERMINATEMSG "\n프로그램을 종료합니다.\n"

#endif