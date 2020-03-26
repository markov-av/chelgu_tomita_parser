#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики

// AlbumName -> 'альбом' AnyWord<h-reg1, l-quoted> AnyWord<~r-quoted>* AnyWord<r-quoted>;
Language -> 'англ' | 'рус';
Brackets -> LBracket (Language) AnyWord* (Language) (AnyWord*) RBracket;

AlbumName -> AnyWord* interp(Music.AlbumName::not_norm) (Brackets interp(Music.Translate)) Hyphen Adj;
GroupName -> Word<kwtype="слово_группа", nc-agr[1]> Word<h-reg1, nc-agr[1]>+ interp(Music.GroupName);

Day -> AnyWord<wff=/([1-2]?[0-9])|(3[0-1])/>; // число от 1 до 31
Month -> Noun<kwtype="месяц">;                // используем слова из статьи "месяц"
YearDescr -> "год" | "г. ";
Year -> Word<wff="(19[0-9]{2})|(20[0-2][0-9])">; // число от 0 до 2999 с возможным "г" или "г." в конце
Year -> Year YearDescr;

S -> AlbumName;
S -> GroupName;
// Album -> GroupName interp (Music.GroupName)
// 	 	 (AlbumName interp (Music.AlbumName));

// Group -> GroupName interp (Music.Group::not_norm);
// Album -> AlbumName interp (Music.Album::not_norm);

Date -> Day interp (Music.Day)
        Month interp (Music.Month)
        (Year interp (Music.Year));
// S -> Group;
// S -> Album;
// Date -> Day Month Year;
S -> Date interp (Music.Date);
S -> Year interp (Music.Year);
// S -> Album interp (Music.Album);
