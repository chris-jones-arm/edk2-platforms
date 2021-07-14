/** @file
*  Heterogeneous Memory Attribute Table (HMAT)
*
*  Copyright (c) 2020-2021, ARM Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include <IndustryStandard/Acpi.h>
#include <Library/ArmLib.h>
#include <Hmat.h>

EFI_ACPI_DESCRIPTION_HEADER HmatHeader = (EFI_ACPI_DESCRIPTION_HEADER) {
        EFI_ACPI_6_4_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_SIGNATURE,
        sizeof (EFI_ACPI_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE),
        EFI_ACPI_6_4_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_REVISION,
        0,
        //('A','R','M','L','T','D'),
        "ARMLTD",
        SIGNATURE_64 ('A','R','M','S','G','I',' ',' '),
        0x20140727,
        SIGNATURE_32('A','R','M',' '),
        0x00000099
      };

//
// HMAT Table
//
EFI_ACPI_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE HmatTable = {
  // Header
  {
    ARM_ACPI_HEADER (
      EFI_ACPI_6_3_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_SIGNATURE,
      EFI_ACPI_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE,
      EFI_ACPI_6_3_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_REVISION
      ),
    {
      EFI_ACPI_RESERVED_BYTE,
      EFI_ACPI_RESERVED_BYTE,
      EFI_ACPI_RESERVED_BYTE,
      EFI_ACPI_RESERVED_BYTE
    },
  },

  // Memory Proximity Domain
  {
    EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_INIT (
      1, 0x0, 0x0),
    EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_INIT (
      1, 0x1, 0x1),
    EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_INIT (
      1, 0x2, 0x2),
    EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_INIT (
      1, 0x3, 0x3),
   },

  // Latency Info
  EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_INIT (
    0, 0, INITATOR_PROXIMITY_DOMAIN_CNT, TARGET_PROXIMITY_DOMAIN_CNT, 100),
  {
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {
      //
      // The latencies mentioned in this table are hypothetical values and
      // represents typical latency between four chips. These values are
      // applicable only for RD-V1-MC quad-chip fixed virtual platform and
      // should not be reused for other platforms.
      //
      10, 20, 20, 20,
      20, 10, 20, 20,
      20, 20, 10, 20,
      20, 20, 20, 10,
    }
  },

  // Memory Side Cache
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_INIT (
    0x0,
    SIZE_1GB,
    HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES_INIT (
      1,
      1,
      2,
      2,
      64 // 64 bytes cache line length
      ),
    0),

  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_INIT (
    0x1,
    SIZE_1GB,
    HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES_INIT (
      1,
      1,
      2,
      2,
      64 // 64 bytes cache line length
      ),
    0),

  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_INIT (
    0x2,
    SIZE_1GB,
    HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES_INIT (
      1,
      1,
      2,
      2,
      64 // 64 bytes cache line length
      ),
    0),

  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_INIT (
    0x3,
    SIZE_1GB,
    HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES_INIT (
      1,
      1,
      2,
      2,
      64 // 64 bytes cache line length
      ),
    0),
};
