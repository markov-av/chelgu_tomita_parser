#encoding "utf-8"

Day -> AnyWord<wff=/([1-2]?[0-9])|(3[0-1])/>; // число от 1 до 31
Month -> Noun<kwtype="месяц">;                // используем слова из статьи "месяц"
YearDescr -> "год" | "г. ";
Year -> Word<wff="(19[0-9]{2})|(20[0-2][0-9])">; // число от 0 до 2999 с возможным "г" или "г." в конце
Year -> Year YearDescr;


        // число, месяц и год: "10 января 2011"
Date -> Day interp (Date.Day)
        Month interp (Date.Month)
        (Year interp (Date.Year));
