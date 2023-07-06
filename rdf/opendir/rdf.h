/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

/* This is the header file for the functions exported from RDF */



typedef struct _RDF_ResourceStruct* RDF_Resource;
typedef struct _RDF_FileStruct* RDFT;
typedef struct _RDF_CursorStruct* RDF_Cursor;
typedef void (*WriteClientProc)(void* obj, char* buffer);

typedef enum { 
  RDF_RESOURCE_TYPE,
  RDF_INT_TYPE,
  RDF_STRING_TYPE
} RDF_ValueType;


void  RDF_Initialize () ;
int RDF_Consume (char* fileName, char* data, int len) ;
void RDF_ReadFile (char* fileName) ;
void RDF_Unload (RDFT f);
RDFT RDF_GetRDFT (char* url, int createp);

RDF_Resource RDF_GetResource (char* url, int createp);
char* RDF_ResourceID(RDF_Resource u);
int RDF_Assert(RDFT db, RDF_Resource u, RDF_Resource s, void* v, RDF_ValueType type);
int RDF_Unassert (RDFT db, RDF_Resource u, RDF_Resource s,  void* v, RDF_ValueType type);

int RDF_HasAssertion (RDFT db, RDF_Resource u, RDF_Resource s, void* v, 
                      RDF_ValueType type);
void* RDF_OnePropValue (RDFT db, RDF_Resource u, RDF_Resource s, RDF_ValueType type);
RDF_Resource RDF_OnePropSource (RDFT db, RDF_Resource u, RDF_Resource s);
RDF_Cursor RDF_GetTargets (RDFT db, RDF_Resource u, RDF_Resource s, RDF_ValueType type);
RDF_Cursor RDF_GetSourcess (RDFT db, RDF_Resource u, RDF_Resource s);
void* RDF_NextValue (RDF_Cursor c) ;
void RDF_DisposeCursor (RDF_Cursor c);

char** RDF_processPathQuery(char* query);
