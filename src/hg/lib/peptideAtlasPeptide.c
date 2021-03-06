/* peptideAtlasPeptide.c was originally generated by the autoSql program, which also 
 * generated peptideAtlasPeptide.h and peptideAtlasPeptide.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "peptideAtlasPeptide.h"



char *peptideAtlasPeptideCommaSepFieldNames = "accession,sequence,sampleCount,hydrophobicity,proteotypicScore";

void peptideAtlasPeptideStaticLoad(char **row, struct peptideAtlasPeptide *ret)
/* Load a row from peptideAtlasPeptide table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->accession = row[0];
ret->sequence = row[1];
ret->sampleCount = sqlSigned(row[2]);
ret->hydrophobicity = sqlFloat(row[3]);
ret->proteotypicScore = sqlFloat(row[4]);
}

struct peptideAtlasPeptide *peptideAtlasPeptideLoad(char **row)
/* Load a peptideAtlasPeptide from row fetched with select * from peptideAtlasPeptide
 * from database.  Dispose of this with peptideAtlasPeptideFree(). */
{
struct peptideAtlasPeptide *ret;

AllocVar(ret);
ret->accession = cloneString(row[0]);
ret->sequence = cloneString(row[1]);
ret->sampleCount = sqlSigned(row[2]);
ret->hydrophobicity = sqlFloat(row[3]);
ret->proteotypicScore = sqlFloat(row[4]);
return ret;
}

struct peptideAtlasPeptide *peptideAtlasPeptideLoadAll(char *fileName) 
/* Load all peptideAtlasPeptide from a whitespace-separated file.
 * Dispose of this with peptideAtlasPeptideFreeList(). */
{
struct peptideAtlasPeptide *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[5];

while (lineFileRow(lf, row))
    {
    el = peptideAtlasPeptideLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct peptideAtlasPeptide *peptideAtlasPeptideLoadAllByChar(char *fileName, char chopper) 
/* Load all peptideAtlasPeptide from a chopper separated file.
 * Dispose of this with peptideAtlasPeptideFreeList(). */
{
struct peptideAtlasPeptide *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[5];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = peptideAtlasPeptideLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct peptideAtlasPeptide *peptideAtlasPeptideCommaIn(char **pS, struct peptideAtlasPeptide *ret)
/* Create a peptideAtlasPeptide out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new peptideAtlasPeptide */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->accession = sqlStringComma(&s);
ret->sequence = sqlStringComma(&s);
ret->sampleCount = sqlSignedComma(&s);
ret->hydrophobicity = sqlFloatComma(&s);
ret->proteotypicScore = sqlFloatComma(&s);
*pS = s;
return ret;
}

void peptideAtlasPeptideFree(struct peptideAtlasPeptide **pEl)
/* Free a single dynamically allocated peptideAtlasPeptide such as created
 * with peptideAtlasPeptideLoad(). */
{
struct peptideAtlasPeptide *el;

if ((el = *pEl) == NULL) return;
freeMem(el->accession);
freeMem(el->sequence);
freez(pEl);
}

void peptideAtlasPeptideFreeList(struct peptideAtlasPeptide **pList)
/* Free a list of dynamically allocated peptideAtlasPeptide's */
{
struct peptideAtlasPeptide *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    peptideAtlasPeptideFree(&el);
    }
*pList = NULL;
}

void peptideAtlasPeptideOutput(struct peptideAtlasPeptide *el, FILE *f, char sep, char lastSep) 
/* Print out peptideAtlasPeptide.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->accession);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->sequence);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%d", el->sampleCount);
fputc(sep,f);
fprintf(f, "%g", el->hydrophobicity);
fputc(sep,f);
fprintf(f, "%g", el->proteotypicScore);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */

