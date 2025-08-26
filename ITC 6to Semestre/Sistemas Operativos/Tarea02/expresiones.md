# nombres

```regex
\b(?:Conrad Reinell|Annie Erickson|Jack Pennies|Mary Livingston|Leo Bing|Peter|Rich Snell Hall|Joan Crawford|Franchot Tone|Mr\. Tone|Will Rogers|Hal Moore|Evelyn Venable|Ed Garner|Axel|Ellen|Bill Warner|Dr\. Hickman|Dr\. Rieger|Florence Gustafsson|Ole Larsen|Ransom|Selma|Lex parent|Rammelisa Jansson|Elin Adele|Carl|Owen|Harold|Walter|Franz Gabrielson|Colonel Gabrielson|Miriam|Carl Anderson|Eleonora Anderson|Britta Matilda Elizabeth Olin|Gustav Vasa|Harlandqvist|Johan Andersson|Patrician Val|Ericsson|Martin|Gunnar|Nordem Highland|Adolf de Kael|Marta|Daniel|Ed Tate|Ruby Hall|Clara Lawson|Roy|Mr\. Rush|Pastor Reina Kron|Pastor Bergström|Pastor Westerberg|Rachel Sward|Pastor Ehrling|Pastor Holt|Pastor Andersson|Richard Pearson|Russell Pearson|Stephanie|Zage|Pastor Palm|Bill|Gus|Fritidsbeteget|Utvandlingsbeteget|Drottningholm|Kungsholm|Viva)\b|\b(?:(?:Mr|Mrs|Miss|Ms|Dr|Pastor|Colonel)\.?\s+)?([A-Z][a-z]+(?:(?:\s+|-)[A-Z][a-z]+){0,2})\b
```

# ubicaciones

```regex
\b(?:Minneapolis|Iowa|Göteborg|New York|United States|Ellis Island|Chicago|Carolina|Canada|Washington|State of Washington|Buffalo|Pontiac|Detroit|Duluth|River Island|Minnesota|Wisconsin|Superior|South Superior|Illinois|Galesburg|Knoxville|Henderson County|Big River Yard|Jameson|California|New York City|Beverly Hills|Long Beach|Jamestown|Pennsylvania|Warwick|Rhode Island|Port Talcott|Providence|Salt Lake City|Hollywood|Hollywood and Vine|Brentwood Heights|England|Europe|Florida|Molin|Amerika|Lin|Lynn|Massachusetts|Owatana|Albert Lee|New Windsor|Michigan|Leamington|Ohio|LA|Winnebago|Rödön|Jämtland|Östersund|Storskön|University of Manitoba|China|Finland|Vasa|Sweden|Gulf of Bosnia|Aspås|Trondheim|Norway|Winnipeg|Klockarnäs|Nygården|Falu|Stockholm|Eriksdale|Minnadosa|Quigley Drive|Klerken|Belgium|East Flanders|West Flanders|Fourth Avenue|14th Street|East Moline|France|Davenport|Third street|Silvis|Holy Trinity|Västlanda|Westland Lutheran church|Bertranda|Adulhamn|Holdridge|Swede Bay|Binksburg|Waterbury|Bunker Hill Congregational Church|New Britain|Connecticut|Los Angeles|San Francisco|New England|Cranston|Olien|Rochester|Nebraska|Swedhåne|Malmö|Sturmsburg|Swedland|Tucson|Arizona|Norwalk|Webster|Läkontariot|Portville|Park Ridge|Schomburg|Kewani|Rockford|Decatur|Malin)\b|\b([A-Z][a-z]+(?:(?:\s+[A-Z][a-z]+){0,2})(?:\s+(?:County|State|Island|Yard|City|Bay|Mountains|Street|Avenue|Heights|Drive))?)\b
```

# tiempos y fechas

```regex
(?i)\b(?:(?:(January|February|March|April|May|June|July|August|September|October|November|December)\s+the\s+\d{1,2}(?:st|nd|rd|th)?)|(?:\d{1,2}(?:st|nd|rd|th)?\s+of\s+(January|February|March|April|May|June|July|August|September|October|November|December))|(?:(?:(January|February|March|April|May|June|July|August|September|October|November|December)\s+\d{1,2},?\s+\d{4})|(?:\d{1,2}\s+(January|February|March|April|May|June|July|August|September|October|November|December),?\s+\d{4}))|(?:\d{1,2}\.\s*(January|February|March|April|May|June|July|August|September|October|November|December)\s+\d{4})|(?:\d{4}[-/]\d{1,2}[-/]\d{1,2})|(?:\d{1,2}[-/.]\d{1,2}[-/.]\d{2,4})|(?:(?:19|20)\d{2}s)|(?:(?:the\s+)?\d{2}s)|(?:(?:first|last|next)\s+(?:day|week|month|year|morning|night))|(?:(?:Monday|Tuesday|Wednesday|Thursday|Friday|Saturday|Sunday)(?:\s+(?:morning|afternoon|evening|night))?)|(?:morning|afternoon|evening|night|tonight|today|yesterday|tomorrow)|(?:(?:midnight|noon))|(?:(?:\d{1,2}(?:[:.]\d{2})?)\s*o'clock)|(?:year\s+2000)|(?:(?:(?:\d+|a|an|one|two|three|four|five|six|seven|eight|nine|ten|eleven|twelve|fifteen|twenty|hundreds)\s+(?:year|month|week|day|hour|minute)s?)|(?:year\s+and\s+a\s+half)|(?:month\s+or\s+two)|(?:ten\s+days)))\b
```

# fechas de nacimiento

```regex
(?i)\b(born(?:\s+on(?:\s+the)?)?)\s*(\d{4}\s+med\s+\d{1,2}\s+(MonthNames)|\d{4},?\s+(MonthNames)\s+\d{1,2}(?:st|nd|rd|th)?|\d{1,2}(?:st|nd|rd|th)?\s+of\s+(MonthNames)|\d{4}[-/]\d{1,2}[-/]\d{1,2}|\d{1,2}[-/.]\d{1,2}[-/.]\d{2,4}|(?:MonthNames)\s+\d{1,2},?\s+\d{4}|\d{1,2}\s+(MonthNames),?\s+\d{4})\b
```

# palabras clave

```regex
(?i)\b(hello|yes|yeah|no|cancelled|urgent)\b
```
