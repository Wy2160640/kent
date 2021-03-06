table rmskOut2
"RepeatMasker .out record"
    (
    uint swScore;       "Smith Waterman alignment score"
    uint milliDiv;      "Base mismatches in parts per thousand"
    uint milliDel;      "Bases deleted in parts per thousand"
    uint milliIns;      "Bases inserted in parts per thousand"
    string genoName;    "Genomic sequence name"
    uint genoStart;     "Start in genomic sequence"
    uint genoEnd;       "End in genomic sequence"
    int  genoLeft;      "-#bases after match in genomic sequence"
    char[1] strand;     "Relative orientation + or -"
    string repName;     "Name of repeat"
    string repClass;    "Class of repeat"
    string repFamily;   "Family of repeat"
    int repStart;       "Start in repeat sequence - regardless of orient."
    uint repEnd;        "End in repeat sequence - reglardless of orient."
    int repLeft;        "-#bases after match in repeat sequence - regardless of orient"
    uint id;            "The ID of the hit. Used to link related fragments"
    )
